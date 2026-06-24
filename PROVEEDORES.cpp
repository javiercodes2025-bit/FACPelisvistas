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

void FACPelisVistas::PROVEEDORES::buscadorTBX_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(codigobarraTXB->Text)) {
		MessageBox::Show("Ingrese un codigo de barra");
		return;
	}
	int id = Convert::ToInt32(codigobarraTXB->Text);
	std::string titulo;
	int anio, duracion;
	if (buscarPeliculaPorId(id, titulo, anio, duracion)) {
		pelinombreTXB->Text = gcnew String(titulo.c_str());
		peliANIOTBX->Text = anio.ToString();
		peliduracionTBX->Text = duracion.ToString();
	}
	else {
		MessageBox::Show("Pelicula no encontrada");
	}
}
