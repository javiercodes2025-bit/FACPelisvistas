#include "FACTURACION.h"
#include "PROVEEDORES.h"
#include "Clientes.h"
#include "Empleados.h"
#include "Stock.h"

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

