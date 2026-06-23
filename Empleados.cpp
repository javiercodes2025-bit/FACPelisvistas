#include "Empleados.h"
#include "LOGIN.h"
#include "CLIENTES.h"

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

