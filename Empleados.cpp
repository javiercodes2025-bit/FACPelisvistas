#include "Empleados.h"
#include "LOGIN.h"
#include "CLIENTES.h"
#include "Stock.h"

void FACPelisVistas::EMPLEADOS::cerrarBTNEMP_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	Login^ log = gcnew Login;
	log->Show();
}

void FACPelisVistas::EMPLEADOS::cliBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	CLIENTES^ cli = gcnew CLIENTES;
	cli->Show();
}

void FACPelisVistas::EMPLEADOS::stockBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	STOCK^ stk = gcnew STOCK;
	stk->Show();
}

