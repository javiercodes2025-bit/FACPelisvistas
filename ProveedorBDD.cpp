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

void cargarProveedores(DataGridView^ grid) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }

        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "SELECT id_proveedor, nombre, telefono, email, Domicilio "
            "FROM proveedor WHERE habi = 1 ORDER BY id_proveedor"
        );

        sql::ResultSet* rs = ps->executeQuery();

        DataTable^ table = gcnew DataTable("Proveedores");

        table->Columns->Add("ID", Int32::typeid);
        table->Columns->Add("Nombre", String::typeid);
        table->Columns->Add("Telefono", String::typeid);
        table->Columns->Add("Email", String::typeid);
        table->Columns->Add("Domicilio", String::typeid);

        while (rs->next()) {
            DataRow^ row = table->NewRow();
            row["ID"] = rs->getInt("id_proveedor");
            row["Nombre"] = gcnew String(rs->getString("nombre").c_str());
            row["Telefono"] = gcnew String(rs->getString("telefono").c_str());
            row["Email"] = gcnew String(rs->getString("email").c_str());
            row["Domicilio"] = gcnew String(rs->getString("Domicilio").c_str());
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

int ingresarProveedor(const std::string& nombre, const std::string& telefono,
    const std::string& email, const std::string& domicilio) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }

        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "INSERT INTO proveedor(nombre, telefono, email, Domicilio) VALUES (?, ?, ?, ?)"
        );
        ps->setString(1, sql::SQLString(nombre));
        ps->setString(2, sql::SQLString(telefono));
        ps->setString(3, sql::SQLString(email));
        ps->setString(4, sql::SQLString(domicilio));
        ps->executeUpdate();
        delete ps;

        sql::PreparedStatement* ps2 = BDDins->prepareStatement(
            "SELECT LAST_INSERT_ID()"
        );
        sql::ResultSet* rs = ps2->executeQuery();
        int id = 0;
        if (rs->next()) {
            id = rs->getInt(1);
        }
        delete rs;
        delete ps2;
        return id;
    }
    catch (sql::SQLException& e) {
        MessageBox::Show(gcnew String(e.what()));
        return 0;
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
        return 0;
    }
}

void ingresarPeliculaXProveedor(int fk_pelicula, int fk_proveedor) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }

        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "INSERT INTO peliculaXproveedor(fk_pelicula, fk_proveedor) VALUES (?, ?)"
        );
        ps->setInt(1, fk_pelicula);
        ps->setInt(2, fk_proveedor);
        ps->executeUpdate();
        delete ps;
    }
    catch (sql::SQLException& e) {
        MessageBox::Show(gcnew String(e.what()));
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
    }
}

void eliminarProveedor(int id) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }
        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "UPDATE proveedor SET habi = 0 WHERE id_proveedor = ?"
        );
        ps->setInt(1, id);
        ps->executeUpdate();
        delete ps;
    }
    catch (sql::SQLException& e) {
        MessageBox::Show(gcnew String(e.what()));
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
    }
}

void modificarProveedor(int id, const std::string& nombre, const std::string& telefono,
    const std::string& email, const std::string& domicilio) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }
        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "UPDATE proveedor SET nombre = ?, telefono = ?, email = ?, Domicilio = ? "
            "WHERE id_proveedor = ? AND habi = 1"
        );
        ps->setString(1, sql::SQLString(nombre));
        ps->setString(2, sql::SQLString(telefono));
        ps->setString(3, sql::SQLString(email));
        ps->setString(4, sql::SQLString(domicilio));
        ps->setInt(5, id);
        ps->executeUpdate();
        delete ps;
    }
    catch (sql::SQLException& e) {
        MessageBox::Show(gcnew String(e.what()));
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
    }
}
