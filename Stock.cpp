#include "Stock.h"
#include "Clientes.h"
#include "Empleados.h"
#include "PROVEEDORES.h"
#include "FACTURACION.h"

void FACPelisVistas::STOCK::cliBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	CLIENTES^ cli = gcnew CLIENTES;
	cli->Show();
}

void FACPelisVistas::STOCK::emplBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	EMPLEADOS^ emp = gcnew EMPLEADOS;
	emp->Show();
}

void FACPelisVistas::STOCK::provBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	PROVEEDORES^ prov = gcnew PROVEEDORES;
	prov->Show();
}
void FACPelisVistas::STOCK::facBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	FACPelisvistas::FACTURACION^ fac = gcnew FACPelisvistas::FACTURACION;
	fac->Show();
}

