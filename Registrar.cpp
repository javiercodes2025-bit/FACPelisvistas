#include "Registrar.h"
#include "LOGIN.h"

void FACPelisVistas::Registrar::atrBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	Login^ log = gcnew Login;
	log->Show();
}

