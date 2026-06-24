#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/prepared_statement.h>
#include "peliVAR.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;

void cargarAdministradores(DataGridView^ grid) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }

        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "SELECT p.id_persona, p.nombre, p.apellido, p.rol, p.password, "
            "doc.numero_documento, doc.tipo, "
            "e.correo, t.numero AS telefono, "
            "d.calle, d.numero AS num_calle, d.ciudad "
            "FROM persona p "
            "LEFT JOIN personaXdocumento pdoc ON p.id_persona = pdoc.fk_empleado "
            "LEFT JOIN documento doc ON pdoc.fk_persona = doc.id_documento AND doc.habilitado = 1 "
            "LEFT JOIN personaXemail pe ON p.id_persona = pe.fk_persona "
            "LEFT JOIN email e ON pe.fk_email = e.id_email AND e.habilitado = 1 "
            "LEFT JOIN personaXtelefonos pt ON p.id_persona = pt.fk_persona "
            "LEFT JOIN telefonos t ON pt.fk_telefono = t.id_telefono AND t.habilitado = 1 "
            "LEFT JOIN personaXdireccion pd ON p.id_persona = pd.fk_persona "
            "LEFT JOIN direccion d ON pd.fk_direccion = d.id_direccion AND d.habilitado = 1 "
            "WHERE (p.rol = 'ADMINISTRADOR' OR p.rol = 'EMPLEADO') AND p.habilitado = 1"
        );

        sql::ResultSet* rs = ps->executeQuery();

        DataTable^ table = gcnew DataTable("Administradores");

        table->Columns->Add("ID", Int32::typeid);
        table->Columns->Add("Nombre", String::typeid);
        table->Columns->Add("Apellido", String::typeid);
        table->Columns->Add("Rol", String::typeid);
        table->Columns->Add("Password", String::typeid);
        table->Columns->Add("Email", String::typeid);
        table->Columns->Add("Telefono", String::typeid);
        table->Columns->Add("NumDoc", String::typeid);
        table->Columns->Add("TipoDoc", String::typeid);
        table->Columns->Add("Calle", String::typeid);
        table->Columns->Add("Numero", String::typeid);
        table->Columns->Add("Ciudad", String::typeid);

        while (rs->next()) {
            DataRow^ row = table->NewRow();
            row["ID"] = rs->getInt("id_persona");
            row["Nombre"] = gcnew String(rs->getString("nombre").c_str());
            row["Apellido"] = gcnew String(rs->getString("apellido").c_str());
            row["Rol"] = gcnew String(rs->getString("rol").c_str());
            row["Password"] = rs->isNull("password") ? String::Empty : gcnew String(rs->getString("password").c_str());
            row["Email"] = rs->isNull("correo") ? String::Empty : gcnew String(rs->getString("correo").c_str());
            row["Telefono"] = rs->isNull("telefono") ? String::Empty : gcnew String(rs->getString("telefono").c_str());
            row["NumDoc"] = rs->isNull("numero_documento") ? String::Empty : gcnew String(rs->getString("numero_documento").c_str());
            row["TipoDoc"] = rs->isNull("tipo") ? String::Empty : gcnew String(rs->getString("tipo").c_str());
            row["Calle"] = rs->isNull("calle") ? String::Empty : gcnew String(rs->getString("calle").c_str());
            row["Numero"] = rs->isNull("num_calle") ? String::Empty : gcnew String(rs->getString("num_calle").c_str());
            row["Ciudad"] = rs->isNull("ciudad") ? String::Empty : gcnew String(rs->getString("ciudad").c_str());
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

void modificarPersonaCompleta(int idPersona, const std::string& nombre, const std::string& apellido,
    const std::string& password, const std::string& rol,
    const std::string& numeroDocumento, const std::string& tipoDocumento,
    const std::string& correo, const std::string& telefono,
    const std::string& calle, const std::string& numero, const std::string& ciudad) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }

        // 1. UPDATE persona
        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "UPDATE persona SET nombre=?, apellido=?, password=?, rol=? WHERE id_persona=?");
        ps->setString(1, sql::SQLString(nombre));
        ps->setString(2, sql::SQLString(apellido));
        ps->setString(3, sql::SQLString(password));
        ps->setString(4, sql::SQLString(rol));
        ps->setInt(5, idPersona);
        ps->executeUpdate();
        delete ps;

        // 2. UPDATE documento
        sql::PreparedStatement* psDocId = BDDins->prepareStatement(
            "SELECT fk_persona FROM personaXdocumento WHERE fk_empleado=?");
        psDocId->setInt(1, idPersona);
        sql::ResultSet* rs = psDocId->executeQuery();
        if (rs->next()) {
            int idDoc = rs->getInt(1);
            delete rs;
            delete psDocId;
            sql::PreparedStatement* psDoc = BDDins->prepareStatement(
                "UPDATE documento SET numero_documento=?, tipo=? WHERE id_documento=?");
            psDoc->setString(1, sql::SQLString(numeroDocumento));
            psDoc->setString(2, sql::SQLString(tipoDocumento));
            psDoc->setInt(3, idDoc);
            psDoc->executeUpdate();
            delete psDoc;
        }
        else {
            delete rs;
            delete psDocId;
        }

        // 3. UPDATE email
        sql::PreparedStatement* psEmailId = BDDins->prepareStatement(
            "SELECT fk_email FROM personaXemail WHERE fk_persona=?");
        psEmailId->setInt(1, idPersona);
        rs = psEmailId->executeQuery();
        if (rs->next()) {
            int idEmail = rs->getInt(1);
            delete rs;
            delete psEmailId;
            sql::PreparedStatement* psEmail = BDDins->prepareStatement(
                "UPDATE email SET correo=? WHERE id_email=?");
            psEmail->setString(1, sql::SQLString(correo));
            psEmail->setInt(2, idEmail);
            psEmail->executeUpdate();
            delete psEmail;
        }
        else {
            delete rs;
            delete psEmailId;
        }

        // 4. UPDATE telefono
        sql::PreparedStatement* psTelId = BDDins->prepareStatement(
            "SELECT fk_telefono FROM personaXtelefonos WHERE fk_persona=?");
        psTelId->setInt(1, idPersona);
        rs = psTelId->executeQuery();
        if (rs->next()) {
            int idTel = rs->getInt(1);
            delete rs;
            delete psTelId;
            sql::PreparedStatement* psTel = BDDins->prepareStatement(
                "UPDATE telefonos SET numero=? WHERE id_telefono=?");
            psTel->setString(1, sql::SQLString(telefono));
            psTel->setInt(2, idTel);
            psTel->executeUpdate();
            delete psTel;
        }
        else {
            delete rs;
            delete psTelId;
        }

        // 5. UPDATE direccion
        sql::PreparedStatement* psDirId = BDDins->prepareStatement(
            "SELECT fk_direccion FROM personaXdireccion WHERE fk_persona=?");
        psDirId->setInt(1, idPersona);
        rs = psDirId->executeQuery();
        if (rs->next()) {
            int idDir = rs->getInt(1);
            delete rs;
            delete psDirId;
            sql::PreparedStatement* psDir = BDDins->prepareStatement(
                "UPDATE direccion SET calle=?, numero=?, ciudad=? WHERE id_direccion=?");
            psDir->setString(1, sql::SQLString(calle));
            psDir->setString(2, sql::SQLString(numero));
            psDir->setString(3, sql::SQLString(ciudad));
            psDir->setInt(4, idDir);
            psDir->executeUpdate();
            delete psDir;
        }
        else {
            delete rs;
            delete psDirId;
        }
    }
    catch (sql::SQLException& e) {
        MessageBox::Show(gcnew String(e.what()));
    }
}
