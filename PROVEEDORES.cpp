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

void FACPelisVistas::PROVEEDORES::ingrBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(codigobarraTXB->Text) || String::IsNullOrWhiteSpace(pelinombreTXB->Text)) {
		MessageBox::Show("Busque una pelicula primero");
		return;
	}
	if (String::IsNullOrWhiteSpace(nombreTBX->Text)) {
		MessageBox::Show("Ingrese el nombre del proveedor");
		return;
	}

	int idPelicula = Convert::ToInt32(codigobarraTXB->Text);

	msclr::interop::marshal_context ctx;
	std::string nombre = ctx.marshal_as<std::string>(nombreTBX->Text);
	std::string telefono = ctx.marshal_as<std::string>(telefonoTBX->Text);
	std::string email = ctx.marshal_as<std::string>(gmailTBX->Text);
	std::string domicilio = ctx.marshal_as<std::string>(domicilioTBX->Text);

	int idProveedor = ingresarProveedor(nombre, telefono, email, domicilio);
	if (idProveedor > 0) {
		ingresarPeliculaXProveedor(idPelicula, idProveedor);
		cargarProveedores(table1);
		codigobarraTXB->Clear();
		pelinombreTXB->Clear();
		peliANIOTBX->Clear();
		peliduracionTBX->Clear();
		nombreTBX->Clear();
		telefonoTBX->Clear();
		gmailTBX->Clear();
		domicilioTBX->Clear();
		MessageBox::Show("Proveedor ingresado correctamente");
	}
}

void FACPelisVistas::PROVEEDORES::table1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex < 0) return;
	DataGridViewRow^ row = table1->Rows[e->RowIndex];
	idproveedorTBX->Text = row->Cells["ID"]->Value->ToString();
	nombreTBX->Text = row->Cells["Nombre"]->Value->ToString();
	telefonoTBX->Text = row->Cells["Telefono"]->Value->ToString();
	gmailTBX->Text = row->Cells["Email"]->Value->ToString();
	domicilioTBX->Text = row->Cells["Domicilio"]->Value->ToString();
}

void FACPelisVistas::PROVEEDORES::eliBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(idproveedorTBX->Text)) {
		MessageBox::Show("Seleccione un proveedor de la tabla");
		return;
	}
	int id = Convert::ToInt32(idproveedorTBX->Text);
	if (MessageBox::Show("Eliminar proveedor?", "Confirmar", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
		eliminarProveedor(id);
		cargarProveedores(table1);
		idproveedorTBX->Clear();
		nombreTBX->Clear();
		telefonoTBX->Clear();
		gmailTBX->Clear();
		domicilioTBX->Clear();
	}
}

void FACPelisVistas::PROVEEDORES::modiBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(idproveedorTBX->Text)) {
		MessageBox::Show("Seleccione un proveedor de la tabla");
		return;
	}
	if (String::IsNullOrWhiteSpace(nombreTBX->Text)) {
		MessageBox::Show("Ingrese el nombre del proveedor");
		return;
	}
	int id = Convert::ToInt32(idproveedorTBX->Text);
	msclr::interop::marshal_context ctx;
	std::string nombre = ctx.marshal_as<std::string>(nombreTBX->Text);
	std::string telefono = ctx.marshal_as<std::string>(telefonoTBX->Text);
	std::string email = ctx.marshal_as<std::string>(gmailTBX->Text);
	std::string domicilio = ctx.marshal_as<std::string>(domicilioTBX->Text);
	modificarProveedor(id, nombre, telefono, email, domicilio);
	cargarProveedores(table1);
	idproveedorTBX->Clear();
	nombreTBX->Clear();
	telefonoTBX->Clear();
	gmailTBX->Clear();
	domicilioTBX->Clear();
	MessageBox::Show("Proveedor modificado correctamente");
}

void FACPelisVistas::PROVEEDORES::codigobarraTXB_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
		e->Handled = true;
	}
}
