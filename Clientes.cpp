#include "Clientes.h"
#include "Empleados.h"
#include "Stock.h"

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
