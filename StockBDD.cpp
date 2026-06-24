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

void cargarPeliculas(DataGridView^ grid) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }

        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "SELECT p.id_pelicula, p.titulo, p.anio, p.duracion, p.precio, "
            "p.decuentoXproducto, COALESCE(s.cantidad, 0) AS cantidad "
            "FROM pelicula p "
            "LEFT JOIN stock s ON p.id_pelicula = s.fk_pelicula "
            "WHERE p.habi = 1 "
            "ORDER BY p.id_pelicula"
        );

        sql::ResultSet* rs = ps->executeQuery();

        DataTable^ table = gcnew DataTable("Peliculas");

        table->Columns->Add("ID", Int32::typeid);
        table->Columns->Add("Titulo", String::typeid);
        table->Columns->Add("Anio", Int32::typeid);
        table->Columns->Add("Duracion", Int32::typeid);
        table->Columns->Add("Precio", String::typeid);
        table->Columns->Add("Descuento", Int32::typeid);
        table->Columns->Add("Cantidad", Int32::typeid);

        while (rs->next()) {
            DataRow^ row = table->NewRow();

            row["ID"] = rs->getInt("id_pelicula");
            row["Titulo"] = gcnew String(rs->getString("titulo").c_str());

            if (rs->isNull("anio"))
                row["Anio"] = DBNull::Value;
            else
                row["Anio"] = rs->getInt("anio");

            if (rs->isNull("duracion"))
                row["Duracion"] = DBNull::Value;
            else
                row["Duracion"] = rs->getInt("duracion");

            if (rs->isNull("precio"))
                row["Precio"] = String::Empty;
            else
                row["Precio"] = gcnew String(rs->getString("precio").c_str());

            if (rs->isNull("decuentoXproducto"))
                row["Descuento"] = DBNull::Value;
            else
                row["Descuento"] = rs->getInt("decuentoXproducto");

            row["Cantidad"] = rs->getInt("cantidad");

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

void eliminarPelicula(int id) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }
        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "UPDATE pelicula SET habi = 0 WHERE id_pelicula = ?"
        );
        ps->setInt(1, id);
        ps->executeUpdate();
        delete ps;
    }
    catch (sql::SQLException& e) {
        MessageBox::Show(gcnew String(e.what()));
    }
}

void ingresarPelicula(const std::string& titulo, int anio, int duracion,
    double precio, int descuento, int cantidad) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }

        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "INSERT INTO pelicula(titulo, anio, duracion, precio, decuentoXproducto) "
            "VALUES (?, ?, ?, ?, ?)"
        );
        ps->setString(1, sql::SQLString(titulo));
        ps->setInt(2, anio);
        ps->setInt(3, duracion);
        ps->setDouble(4, precio);
        ps->setInt(5, descuento);
        ps->executeUpdate();
        delete ps;

        sql::PreparedStatement* ps2 = BDDins->prepareStatement(
            "INSERT INTO stock(fk_pelicula, cantidad) VALUES (LAST_INSERT_ID(), ?)"
        );
        ps2->setInt(1, cantidad);
        ps2->executeUpdate();
        delete ps2;
    }
    catch (sql::SQLException& e) {
        MessageBox::Show(gcnew String(e.what()));
    }
}

void actualizarPelicula(int id, const std::string& titulo, int anio, int duracion,
    double precio, int descuento, int cantidad) {
    try {
        if (!BDDins || BDDins->isClosed()) {
            conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
            temp.conectVoid();
        }

        sql::PreparedStatement* ps = BDDins->prepareStatement(
            "UPDATE pelicula SET titulo = ?, anio = ?, duracion = ?, precio = ?, decuentoXproducto = ? "
            "WHERE id_pelicula = ?"
        );
        ps->setString(1, sql::SQLString(titulo));
        ps->setInt(2, anio);
        ps->setInt(3, duracion);
        ps->setDouble(4, precio);
        ps->setInt(5, descuento);
        ps->setInt(6, id);
        ps->executeUpdate();
        delete ps;

        sql::PreparedStatement* ps2 = BDDins->prepareStatement(
            "SELECT id_stock FROM stock WHERE fk_pelicula = ?"
        );
        ps2->setInt(1, id);
        sql::ResultSet* rs = ps2->executeQuery();
        if (rs->next()) {
            delete rs;
            delete ps2;
            sql::PreparedStatement* ps3 = BDDins->prepareStatement(
                "UPDATE stock SET cantidad = ? WHERE fk_pelicula = ?"
            );
            ps3->setInt(1, cantidad);
            ps3->setInt(2, id);
            ps3->executeUpdate();
            delete ps3;
        }
        else {
            delete rs;
            delete ps2;
            sql::PreparedStatement* ps4 = BDDins->prepareStatement(
                "INSERT INTO stock(fk_pelicula, cantidad) VALUES (?, ?)"
            );
            ps4->setInt(1, id);
            ps4->setInt(2, cantidad);
            ps4->executeUpdate();
            delete ps4;
        }
    }
    catch (sql::SQLException& e) {
        MessageBox::Show(gcnew String(e.what()));
    }
}
