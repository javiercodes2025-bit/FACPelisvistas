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
	std::string doc = msclr::interop::marshal_as<std::string>(buscadorClienteBTX->Text);
	try {
		if (!BDDins || BDDins->isClosed()) {
			conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
			temp.conectVoid();
		}
		sql::PreparedStatement* ps = BDDins->prepareStatement(
			"SELECT p.nombre, p.apellido "
			"FROM persona p "
			"JOIN personaXdocumento pdoc ON p.id_persona = pdoc.fk_empleado "
			"JOIN documento doc ON pdoc.fk_persona = doc.id_documento "
			"WHERE doc.numero_documento = ? AND doc.habilitado = 1 "
			"AND p.habilitado = 1 AND p.rol = 'CLIENTE'"
		);
		ps->setString(1, sql::SQLString(doc));
		sql::ResultSet* rs = ps->executeQuery();
		if (rs->next()) {
			nombreClienteBTX->Text = gcnew String(rs->getString("nombre").c_str()) + " " +
				gcnew String(rs->getString("apellido").c_str());
		}
		else {
			MessageBox::Show("No existe");
			nombreClienteBTX->Text = L"";
		}
		delete rs;
		delete ps;
	}
	catch (sql::SQLException& ex) {
		MessageBox::Show(gcnew String(ex.what()));
	}
}

