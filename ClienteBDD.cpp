#include <iostream>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/prepared_statement.h>
#include "peliVAR.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;

void cargarClientes(DataGridView^ grid) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }

        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "SELECT p.id_persona, p.nombre, p.apellido, p.password, "
            "doc.numero_documento, doc.tipo, "
            "e.correo, "
            "t.numero AS telefono, "
            "d.calle, d.numero, d.ciudad "
            "FROM persona p "
            "JOIN cliente c ON p.id_persona = c.fk_persona "
            "LEFT JOIN personaXdocumento pdoc ON p.id_persona = pdoc.fk_empleado "
            "LEFT JOIN documento doc ON pdoc.fk_persona = doc.id_documento "
            "LEFT JOIN personaXemail pe ON p.id_persona = pe.fk_persona "
            "LEFT JOIN email e ON pe.fk_email = e.id_email "
            "LEFT JOIN personaXtelefonos pt ON p.id_persona = pt.fk_persona "
            "LEFT JOIN telefonos t ON pt.fk_telefono = t.id_telefono "
            "LEFT JOIN personaXdireccion pd ON p.id_persona = pd.fk_persona "
            "LEFT JOIN direccion d ON pd.fk_direccion = d.id_direccion "
            "WHERE p.habilitado = 1 "
            "ORDER BY p.id_persona"
        );

        sql::ResultSet* rs = ps->executeQuery();

        DataTable^ table = gcnew DataTable("Clientes");

        table->Columns->Add("ID", Int32::typeid);
        table->Columns->Add("Nombre", String::typeid);
        table->Columns->Add("Apellido", String::typeid);
        table->Columns->Add("Password", String::typeid);
        table->Columns->Add("NumDocumento", String::typeid);
        table->Columns->Add("TipoDocumento", String::typeid);
        table->Columns->Add("Email", String::typeid);
        table->Columns->Add("Telefono", String::typeid);
        table->Columns->Add("Calle", String::typeid);
        table->Columns->Add("Numero", String::typeid);
        table->Columns->Add("Ciudad", String::typeid);

        while (rs->next()) {
            DataRow^ row = table->NewRow();

            row["ID"] = rs->getInt("id_persona");
            row["Nombre"] = gcnew String(rs->getString("nombre").c_str());
            row["Apellido"] = gcnew String(rs->getString("apellido").c_str());

            if (rs->isNull("password"))
                row["Password"] = String::Empty;
            else
                row["Password"] = gcnew String(rs->getString("password").c_str());

            if (rs->isNull("numero_documento"))
                row["NumDocumento"] = String::Empty;
            else
                row["NumDocumento"] = gcnew String(rs->getString("numero_documento").c_str());

            if (rs->isNull("tipo"))
                row["TipoDocumento"] = String::Empty;
            else
                row["TipoDocumento"] = gcnew String(rs->getString("tipo").c_str());

            if (rs->isNull("correo"))
                row["Email"] = String::Empty;
            else
                row["Email"] = gcnew String(rs->getString("correo").c_str());

            if (rs->isNull("telefono"))
                row["Telefono"] = String::Empty;
            else
                row["Telefono"] = gcnew String(rs->getString("telefono").c_str());

            if (rs->isNull("calle"))
                row["Calle"] = String::Empty;
            else
                row["Calle"] = gcnew String(rs->getString("calle").c_str());

            if (rs->isNull("numero"))
                row["Numero"] = String::Empty;
            else
                row["Numero"] = gcnew String(rs->getString("numero").c_str());

            if (rs->isNull("ciudad"))
                row["Ciudad"] = String::Empty;
            else
                row["Ciudad"] = gcnew String(rs->getString("ciudad").c_str());

            table->Rows->Add(row);
        }

        delete rs;
        delete ps;

        grid->DataSource = table;
        grid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
    }
    catch (sql::SQLException& e) {
        MessageBox::Show(gcnew String(e.what()));
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
    }
}

int insertarCliente(const std::string& nombre, const std::string& apellido, const std::string& password,
    const std::string& nroDocumento, const std::string& tipoDocumento,
    const std::string& correo, const std::string& telefono,
    const std::string& calle, const std::string& numero, const std::string& ciudad) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }

        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "INSERT INTO persona(nombre, apellido, password, rol) VALUES (?, ?, ?, 'CLIENTE')"
        );
        ps->setString(1, sql::SQLString(nombre));
        ps->setString(2, sql::SQLString(apellido));
        ps->setString(3, sql::SQLString(password));
        ps->executeUpdate();
        delete ps;

        sql::Statement* stmt = BDDins->createStatement();
        sql::ResultSet* rs = stmt->executeQuery("SELECT LAST_INSERT_ID()");
        int idPersona = 0;
        if (rs->next())
            idPersona = rs->getInt(1);
        delete rs;
        delete stmt;

        sql::PreparedStatement* psDoc = BDDins->prepareStatement(
            "INSERT INTO documento(numero_documento, tipo) VALUES (?, ?)"
        );
        psDoc->setString(1, sql::SQLString(nroDocumento));
        psDoc->setString(2, sql::SQLString(tipoDocumento));
        psDoc->executeUpdate();
        delete psDoc;

        stmt = BDDins->createStatement();
        rs = stmt->executeQuery("SELECT LAST_INSERT_ID()");
        int idDocumento = 0;
        if (rs->next())
            idDocumento = rs->getInt(1);
        delete rs;
        delete stmt;

        sql::PreparedStatement* psPerDoc = BDDins->prepareStatement(
            "INSERT INTO personaXdocumento(fk_empleado, fk_persona) VALUES (?, ?)"
        );
        psPerDoc->setInt(1, idPersona);
        psPerDoc->setInt(2, idDocumento);
        psPerDoc->executeUpdate();
        delete psPerDoc;

        sql::PreparedStatement* psEmail = BDDins->prepareStatement(
            "INSERT INTO email(correo) VALUES (?)"
        );
        psEmail->setString(1, sql::SQLString(correo));
        psEmail->executeUpdate();
        delete psEmail;

        stmt = BDDins->createStatement();
        rs = stmt->executeQuery("SELECT LAST_INSERT_ID()");
        int idEmail = 0;
        if (rs->next())
            idEmail = rs->getInt(1);
        delete rs;
        delete stmt;

        sql::PreparedStatement* psPerEmail = BDDins->prepareStatement(
            "INSERT INTO personaXemail(fk_persona, fk_email) VALUES (?, ?)"
        );
        psPerEmail->setInt(1, idPersona);
        psPerEmail->setInt(2, idEmail);
        psPerEmail->executeUpdate();
        delete psPerEmail;

        sql::PreparedStatement* psTel = BDDins->prepareStatement(
            "INSERT INTO telefonos(numero) VALUES (?)"
        );
        psTel->setString(1, sql::SQLString(telefono));
        psTel->executeUpdate();
        delete psTel;

        stmt = BDDins->createStatement();
        rs = stmt->executeQuery("SELECT LAST_INSERT_ID()");
        int idTelefono = 0;
        if (rs->next())
            idTelefono = rs->getInt(1);
        delete rs;
        delete stmt;

        sql::PreparedStatement* psPerTel = BDDins->prepareStatement(
            "INSERT INTO personaXtelefonos(fk_persona, fk_telefono) VALUES (?, ?)"
        );
        psPerTel->setInt(1, idPersona);
        psPerTel->setInt(2, idTelefono);
        psPerTel->executeUpdate();
        delete psPerTel;

        sql::PreparedStatement* psDir = BDDins->prepareStatement(
            "INSERT INTO direccion(calle, numero, ciudad) VALUES (?, ?, ?)"
        );
        psDir->setString(1, sql::SQLString(calle));
        psDir->setString(2, sql::SQLString(numero));
        psDir->setString(3, sql::SQLString(ciudad));
        psDir->executeUpdate();
        delete psDir;

        stmt = BDDins->createStatement();
        rs = stmt->executeQuery("SELECT LAST_INSERT_ID()");
        int idDireccion = 0;
        if (rs->next())
            idDireccion = rs->getInt(1);
        delete rs;
        delete stmt;

        sql::PreparedStatement* psPerDir = BDDins->prepareStatement(
            "INSERT INTO personaXdireccion(fk_persona, fk_direccion) VALUES (?, ?)"
        );
        psPerDir->setInt(1, idPersona);
        psPerDir->setInt(2, idDireccion);
        psPerDir->executeUpdate();
        delete psPerDir;

        sql::PreparedStatement* psCli = BDDins->prepareStatement(
            "INSERT INTO cliente(fk_persona) VALUES (?)"
        );
        psCli->setInt(1, idPersona);
        psCli->executeUpdate();
        delete psCli;

        return idPersona;
    }
    catch (sql::SQLException& e) {
        MessageBox::Show(gcnew String(e.what()));
        return 0;
    }
}

void eliminarCliente(int idPersona) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }
        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "UPDATE persona SET habilitado = 0 WHERE id_persona = ?"
        );
        ps->setInt(1, idPersona);
        ps->executeUpdate();
        delete ps;
    }
    catch (sql::SQLException& e) {
        MessageBox::Show(gcnew String(e.what()));
    }
}

void modificarCliente(int idPersona,
    const std::string& nombre, const std::string& apellido, const std::string& password,
    const std::string& nroDocumento, const std::string& tipoDocumento,
    const std::string& correo, const std::string& telefono,
    const std::string& calle, const std::string& numero, const std::string& ciudad) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }

        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "UPDATE persona SET nombre = ?, apellido = ?, password = ? WHERE id_persona = ?"
        );
        ps->setString(1, sql::SQLString(nombre));
        ps->setString(2, sql::SQLString(apellido));
        ps->setString(3, sql::SQLString(password));
        ps->setInt(4, idPersona);
        ps->executeUpdate();
        delete ps;

        sql::PreparedStatement* psSel = BDDins->prepareStatement(
            "SELECT fk_persona FROM personaXdocumento WHERE fk_empleado = ?"
        );
        psSel->setInt(1, idPersona);
        sql::ResultSet* rs = psSel->executeQuery();
        int idDoc = 0;
        if (rs->next()) idDoc = rs->getInt(1);
        delete rs;
        delete psSel;

        if (idDoc > 0) {
            ps = BDDins->prepareStatement(
                "UPDATE documento SET numero_documento = ?, tipo = ? WHERE id_documento = ?"
            );
            ps->setString(1, sql::SQLString(nroDocumento));
            ps->setString(2, sql::SQLString(tipoDocumento));
            ps->setInt(3, idDoc);
            ps->executeUpdate();
            delete ps;
        }

        psSel = BDDins->prepareStatement(
            "SELECT fk_email FROM personaXemail WHERE fk_persona = ?"
        );
        psSel->setInt(1, idPersona);
        rs = psSel->executeQuery();
        int idEmail = 0;
        if (rs->next()) idEmail = rs->getInt(1);
        delete rs;
        delete psSel;

        if (idEmail > 0) {
            ps = BDDins->prepareStatement(
                "UPDATE email SET correo = ? WHERE id_email = ?"
            );
            ps->setString(1, sql::SQLString(correo));
            ps->setInt(2, idEmail);
            ps->executeUpdate();
            delete ps;
        }

        psSel = BDDins->prepareStatement(
            "SELECT fk_telefono FROM personaXtelefonos WHERE fk_persona = ?"
        );
        psSel->setInt(1, idPersona);
        rs = psSel->executeQuery();
        int idTel = 0;
        if (rs->next()) idTel = rs->getInt(1);
        delete rs;
        delete psSel;

        if (idTel > 0) {
            ps = BDDins->prepareStatement(
                "UPDATE telefonos SET numero = ? WHERE id_telefono = ?"
            );
            ps->setString(1, sql::SQLString(telefono));
            ps->setInt(2, idTel);
            ps->executeUpdate();
            delete ps;
        }

        psSel = BDDins->prepareStatement(
            "SELECT fk_direccion FROM personaXdireccion WHERE fk_persona = ?"
        );
        psSel->setInt(1, idPersona);
        rs = psSel->executeQuery();
        int idDir = 0;
        if (rs->next()) idDir = rs->getInt(1);
        delete rs;
        delete psSel;

        if (idDir > 0) {
            ps = BDDins->prepareStatement(
                "UPDATE direccion SET calle = ?, numero = ?, ciudad = ? WHERE id_direccion = ?"
            );
            ps->setString(1, sql::SQLString(calle));
            ps->setString(2, sql::SQLString(numero));
            ps->setString(3, sql::SQLString(ciudad));
            ps->setInt(4, idDir);
            ps->executeUpdate();
            delete ps;
        }
    }
    catch (sql::SQLException& e) {
        MessageBox::Show(gcnew String(e.what()));
    }
}
