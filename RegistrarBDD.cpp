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
            "SELECT p.id_persona, p.nombre, p.apellido, p.rol, "
            "e.correo, t.numero AS telefono, "
            "d.calle, d.numero AS num_calle, d.ciudad "
            "FROM persona p "
            "LEFT JOIN personaXemail pe ON p.id_persona = pe.fk_persona "
            "LEFT JOIN email e ON pe.fk_email = e.id_email AND e.habilitado = 1 "
            "LEFT JOIN personaXtelefonos pt ON p.id_persona = pt.fk_persona "
            "LEFT JOIN telefonos t ON pt.fk_telefono = t.id_telefono AND t.habilitado = 1 "
            "LEFT JOIN personaXdireccion pd ON p.id_persona = pd.fk_persona "
            "LEFT JOIN direccion d ON pd.fk_direccion = d.id_direccion AND d.habilitado = 1 "
            "WHERE p.rol = 'ADMINISTRADOR' AND p.habilitado = 1"
        );

        sql::ResultSet* rs = ps->executeQuery();

        DataTable^ table = gcnew DataTable("Administradores");

        table->Columns->Add("ID", Int32::typeid);
        table->Columns->Add("Nombre", String::typeid);
        table->Columns->Add("Apellido", String::typeid);
        table->Columns->Add("Rol", String::typeid);
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
            row["Rol"] = gcnew String(rs->getString("rol").c_str());
            row["Email"] = rs->isNull("correo") ? String::Empty : gcnew String(rs->getString("correo").c_str());
            row["Telefono"] = rs->isNull("telefono") ? String::Empty : gcnew String(rs->getString("telefono").c_str());
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
