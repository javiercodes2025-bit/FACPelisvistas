#include "PROVEEDORES.h"
#include "CLIENTES.h"
#include "Empleados.h"
#include "Stock.h"

void FACPelisVistas::PROVEEDORES::stockBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	STOCK^ stk = gcnew STOCK;
	stk->Show();
}

void FACPelisVistas::PROVEEDORES::cliBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	CLIENTES^ cli = gcnew CLIENTES;
	cli->Show();
}

void FACPelisVistas::PROVEEDORES::emplBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	EMPLEADOS^ emp = gcnew EMPLEADOS;
	emp->Show();
}
