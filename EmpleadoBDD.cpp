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

void cargarEmpleados(DataGridView^ grid) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }

        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "SELECT p.id_persona, p.nombre, p.apellido, p.rol, "
            "doc.numero_documento, "
            "e.correo, "
            "t.numero AS telefono, "
            "emp.hora_entrada, emp.hora_salida, emp.sueldo "
            "FROM persona p "
            "LEFT JOIN personaXdocumento pdoc ON p.id_persona = pdoc.fk_empleado "
            "LEFT JOIN documento doc ON pdoc.fk_persona = doc.id_documento "
            "LEFT JOIN personaXemail pe ON p.id_persona = pe.fk_persona "
            "LEFT JOIN email e ON pe.fk_email = e.id_email "
            "LEFT JOIN personaXtelefonos pt ON p.id_persona = pt.fk_persona "
            "LEFT JOIN telefonos t ON pt.fk_telefono = t.id_telefono "
            "LEFT JOIN empleado emp ON p.id_persona = emp.fk_persona "
            "WHERE (p.rol = 'EMPLEADO' OR p.rol = 'ADMINISTRADOR') AND p.habilitado = 1 "
            "ORDER BY p.id_persona"
        );

        sql::ResultSet* rs = ps->executeQuery();

        DataTable^ table = gcnew DataTable("Empleados");

        table->Columns->Add("ID", Int32::typeid);
        table->Columns->Add("Nombre", String::typeid);
        table->Columns->Add("Apellido", String::typeid);
        table->Columns->Add("Rol", String::typeid);
        table->Columns->Add("NumDocumento", String::typeid);
        table->Columns->Add("Email", String::typeid);
        table->Columns->Add("Telefono", String::typeid);
        table->Columns->Add("HoraEntrada", String::typeid);
        table->Columns->Add("HoraSalida", String::typeid);
        table->Columns->Add("Sueldo", Int32::typeid);

        while (rs->next()) {
            DataRow^ row = table->NewRow();

            row["ID"] = rs->getInt("id_persona");
            row["Nombre"] = gcnew String(rs->getString("nombre").c_str());
            row["Apellido"] = gcnew String(rs->getString("apellido").c_str());
            row["Rol"] = gcnew String(rs->getString("rol").c_str());
            if (rs->isNull("numero_documento"))
                row["NumDocumento"] = String::Empty;
            else
                row["NumDocumento"] = gcnew String(rs->getString("numero_documento").c_str());

            if (rs->isNull("correo"))
                row["Email"] = String::Empty;
            else
                row["Email"] = gcnew String(rs->getString("correo").c_str());

            if (rs->isNull("telefono"))
                row["Telefono"] = String::Empty;
            else
                row["Telefono"] = gcnew String(rs->getString("telefono").c_str());

            if (rs->isNull("hora_entrada"))
                row["HoraEntrada"] = String::Empty;
            else
                row["HoraEntrada"] = gcnew String(rs->getString("hora_entrada").c_str());

            if (rs->isNull("hora_salida"))
                row["HoraSalida"] = String::Empty;
            else
                row["HoraSalida"] = gcnew String(rs->getString("hora_salida").c_str());

            if (rs->isNull("sueldo"))
                row["Sueldo"] = DBNull::Value;
            else
                row["Sueldo"] = rs->getInt("sueldo");

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

int buscarPersonaPorDocumento(const std::string& documento, std::string& nombre, std::string& apellido) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }

        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "SELECT p.id_persona, p.nombre, p.apellido "
            "FROM persona p "
            "JOIN personaXdocumento pdoc ON p.id_persona = pdoc.fk_empleado "
            "JOIN documento doc ON pdoc.fk_persona = doc.id_documento "
            "WHERE doc.numero_documento = ?"
        );

        ps->setString(1, sql::SQLString(documento));
        sql::ResultSet* rs = ps->executeQuery();

        int idPersona = 0;
        if (rs->next()) {
            idPersona = rs->getInt("id_persona");
            nombre = rs->getString("nombre").c_str();
            apellido = rs->getString("apellido").c_str();
        }

        delete rs;
        delete ps;
        return idPersona;
    }
    catch (sql::SQLException& e) {
        MessageBox::Show(gcnew String(e.what()));
        return 0;
    }
}

bool existeEmpleado(int idPersona) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }
        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "SELECT COUNT(*) FROM empleado WHERE fk_persona = ?"
        );
        ps->setInt(1, idPersona);
        sql::ResultSet* rs = ps->executeQuery();
        bool existe = false;
        if (rs->next()) {
            existe = rs->getInt(1) > 0;
        }
        delete rs;
        delete ps;
        return existe;
    }
    catch (sql::SQLException& e) {
        MessageBox::Show(gcnew String(e.what()));
        return false;
    }
}

void insertarEmpleado(int idPersona, const std::string& horaEntrada, const std::string& horaSalida, int sueldo) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }

        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "INSERT INTO empleado(fk_persona, hora_entrada, hora_salida, sueldo) "
            "VALUES (?, ?, ?, ?)"
        );

        ps->setInt(1, idPersona);
        ps->setString(2, sql::SQLString(horaEntrada));
        ps->setString(3, sql::SQLString(horaSalida));
        ps->setInt(4, sueldo);
        ps->executeUpdate();

        delete ps;
    }
    catch (sql::SQLException& e) {
        MessageBox::Show(gcnew String(e.what()));
    }
}

void eliminarPersona(int idPersona) {
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

void modificarEmpleado(int idPersona, const std::string& horaEntrada, const std::string& horaSalida, int sueldo) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }
        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "UPDATE empleado SET hora_entrada = ?, hora_salida = ?, sueldo = ? WHERE fk_persona = ?"
        );
        ps->setString(1, sql::SQLString(horaEntrada));
        ps->setString(2, sql::SQLString(horaSalida));
        ps->setInt(3, sueldo);
        ps->setInt(4, idPersona);
        ps->executeUpdate();
        delete ps;
    }
    catch (sql::SQLException& e) {
        MessageBox::Show(gcnew String(e.what()));
    }
}
