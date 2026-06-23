#include "Clientes.h"
#include "Empleados.h"

void FACPelisVistas::CLIENTES::emplBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	EMPLEADOS^ emp = gcnew EMPLEADOS;
	emp->Show();
}
