#include "Clientes.h"
#include "Empleados.h"
#include "Stock.h"
#include "PROVEEDORES.h"
#include "FACTURACION.h"

void FACPelisVistas::CLIENTES::emplBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	EMPLEADOS^ emp = gcnew EMPLEADOS;
	emp->Show();
}

void FACPelisVistas::CLIENTES::stockBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	STOCK^ stk = gcnew STOCK;
	stk->Show();
}

void FACPelisVistas::CLIENTES::provBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	PROVEEDORES^ prov = gcnew PROVEEDORES;
	prov->Show();
}
void FACPelisVistas::CLIENTES::facBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	FACPelisvistas::FACTURACION^ fac = gcnew FACPelisvistas::FACTURACION;
	fac->Show();
}
