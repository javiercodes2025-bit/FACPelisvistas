#include "FACTURACION.h"
#include "PROVEEDORES.h"
#include "Clientes.h"
#include "Empleados.h"
#include "Stock.h"
#include <msclr/marshal_cppstd.h>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/prepared_statement.h>
#include "peliVAR.h"

void FACPelisvistas::FACTURACION::proveedoresBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	FACPelisVistas::PROVEEDORES^ prov = gcnew FACPelisVistas::PROVEEDORES;
	prov->Show();
}
void FACPelisvistas::FACTURACION::empleadosBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	FACPelisVistas::EMPLEADOS^ emp = gcnew FACPelisVistas::EMPLEADOS;
	emp->Show();
}
void FACPelisvistas::FACTURACION::clienteBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	FACPelisVistas::CLIENTES^ cli = gcnew FACPelisVistas::CLIENTES;
	cli->Show();
}
void FACPelisvistas::FACTURACION::stockBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	FACPelisVistas::STOCK^ stk = gcnew FACPelisVistas::STOCK;
	stk->Show();
}
void FACPelisvistas::FACTURACION::buscadorClienteBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(buscadorClienteBTX->Text)) return;
	int idPersona;
	if (!Int32::TryParse(buscadorClienteBTX->Text, idPersona)) return;
	try {
		if (!BDDins || BDDins->isClosed()) {
			conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
			temp.conectVoid();
		}
		sql::PreparedStatement* ps = BDDins->prepareStatement(
			"SELECT p.nombre, p.apellido, p.habilitado "
			"FROM persona p "
			"WHERE p.id_persona = ?"
		);
		ps->setInt(1, idPersona);
		sql::ResultSet* rs = ps->executeQuery();
		if (rs->next()) {
			if (rs->getInt("habilitado") == 0) {
				MessageBox::Show("Existe pero habilitado = 0");
				nombreClienteBTX->Text = L"";
			} else {
				nombreClienteBTX->Text = gcnew String(rs->getString("nombre").c_str()) + " " +
					gcnew String(rs->getString("apellido").c_str());
			}
		} else {
			MessageBox::Show("Esa persona no existe.. ");
			nombreClienteBTX->Text = L"";
		}
		delete rs;
		delete ps;
	}
	catch (sql::SQLException& ex) {
		MessageBox::Show(gcnew String(ex.what()));
	}
}
void FACPelisvistas::FACTURACION::buscarProBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(CodigoBarraTBX->Text)) return;
	int idPelicula;
	if (!Int32::TryParse(CodigoBarraTBX->Text, idPelicula)) return;
	try {
		if (!BDDins || BDDins->isClosed()) {
			conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
			temp.conectVoid();
		}
		sql::PreparedStatement* ps = BDDins->prepareStatement(
			"SELECT p.titulo, p.precio, p.decuentoXproducto, s.cantidad "
			"FROM pelicula p "
			"LEFT JOIN stock s ON p.id_pelicula = s.fk_pelicula "
			"WHERE p.id_pelicula = ? AND p.habi = 1"
		);
		ps->setInt(1, idPelicula);
		sql::ResultSet* rs = ps->executeQuery();
		if (rs->next()) {
			nombrepeliTBX->Text = gcnew String(rs->getString("titulo").c_str());
			precioTBX->Text = gcnew String(rs->getString("precio").c_str());
			descuentoXproducBTX->Text = gcnew String(rs->getString("decuentoXproducto").c_str());
			if (rs->isNull("cantidad"))
				stockTBX->Text = L"0";
			else
				stockTBX->Text = gcnew String(rs->getString("cantidad").c_str());
		}
		else {
			MessageBox::Show("Esa pelicula no existe");
			nombrepeliTBX->Text = L"";
			precioTBX->Text = L"";
			descuentoXproducBTX->Text = L"";
			stockTBX->Text = L"";
		}
		delete rs;
		delete ps;
	}
	catch (sql::SQLException& ex) {
		MessageBox::Show(gcnew String(ex.what()));
	}
}

