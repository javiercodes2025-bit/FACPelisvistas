#pragma once
#include "peliVAR.h"
ref class Login;
ref class CLIENTES;
ref class STOCK;
ref class PROVEEDORES;

#include <msclr/marshal_cppstd.h>

void cargarEmpleados(System::Windows::Forms::DataGridView^ grid);
int buscarPersonaPorDocumento(const std::string& documento, std::string& nombre, std::string& apellido);
bool existeEmpleado(int idPersona);
void insertarEmpleado(int idPersona, const std::string& horaEntrada, const std::string& horaSalida, int sueldo);
void eliminarPersona(int idPersona);
void modificarEmpleado(int idPersona, const std::string& horaEntrada, const std::string& horaSalida, int sueldo);
/* para q and�  los cambios de vistas... en BTN
#include <".h">
#include <".h">
#include <".h">
#include <".h"> */


namespace FACPelisVistas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de EMPLEADOS
	/// </summary>
	public ref class EMPLEADOS : public System::Windows::Forms::Form
	{
	private: int idPersonaEncontrada;
	private: bool modoModificar;
	public:
		EMPLEADOS(void)
		{
			InitializeComponent();
			idPersonaEncontrada = 0;
			modoModificar = false;

			System::Windows::Forms::FlowLayoutPanel^ topPanel = gcnew System::Windows::Forms::FlowLayoutPanel();
			topPanel->Location = System::Drawing::Point(12, 28);
			topPanel->Size = System::Drawing::Size(this->ClientSize.Width - 24, 30);
			topPanel->Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right;
			topPanel->FlowDirection = System::Windows::Forms::FlowDirection::LeftToRight;

			topPanel->Controls->Add(this->facBTN);
			topPanel->Controls->Add(this->cliBTN);
			topPanel->Controls->Add(this->provBTN);
			topPanel->Controls->Add(this->stockBTN);

			this->Controls->Add(topPanel);

			this->ingrBTN->Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right;
			this->eliBTN->Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right;
			this->modiBTN->Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right;

			this->sueldoTBX->Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right;
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right;

			this->table1->Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right;

		

			this->MinimumSize = System::Drawing::Size(800, 600);

			cargarEmpleados(this->table1);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~EMPLEADOS()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ facBTN;
	private: System::Windows::Forms::Button^ cliBTN;
	private: System::Windows::Forms::Button^ provBTN;
	private: System::Windows::Forms::Button^ stockBTN;
	private: System::Windows::Forms::Button^ ingrBTN;


	private: System::Windows::Forms::Button^ eliBTN;

	private: System::Windows::Forms::Button^ modiBTN;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;

	private: System::Windows::Forms::TextBox^ nombreTBX;
	private: System::Windows::Forms::TextBox^ apellidoTBX;

	private: System::Windows::Forms::TextBox^ idTBX;






	private: System::Windows::Forms::DataGridView^ table1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ entrTBX;
	private: System::Windows::Forms::TextBox^ saliTBX;
	private: System::Windows::Forms::TextBox^ sueldoTBX;



	private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Button^ buscarBTN;
private: System::Windows::Forms::Button^ cerrarBTNEMP;






	protected:

	protected:




	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->facBTN = (gcnew System::Windows::Forms::Button());
			this->cliBTN = (gcnew System::Windows::Forms::Button());
			this->provBTN = (gcnew System::Windows::Forms::Button());
			this->stockBTN = (gcnew System::Windows::Forms::Button());
			this->ingrBTN = (gcnew System::Windows::Forms::Button());
			this->eliBTN = (gcnew System::Windows::Forms::Button());
			this->modiBTN = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->idTBX = (gcnew System::Windows::Forms::TextBox());
			this->table1 = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->entrTBX = (gcnew System::Windows::Forms::TextBox());
			this->saliTBX = (gcnew System::Windows::Forms::TextBox());
			this->sueldoTBX = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->buscarBTN = (gcnew System::Windows::Forms::Button());
			this->cerrarBTNEMP = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->nombreTBX = (gcnew System::Windows::Forms::TextBox());
			this->apellidoTBX = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table1))->BeginInit();
			this->SuspendLayout();
			// 
			// facBTN
			// 
			this->facBTN->Location = System::Drawing::Point(35, 42);
			this->facBTN->Name = L"facBTN";
			this->facBTN->Size = System::Drawing::Size(172, 26);
			this->facBTN->TabIndex = 0;
			this->facBTN->Text = L"FACTURACION";
			this->facBTN->UseVisualStyleBackColor = true;
			this->facBTN->Click += gcnew System::EventHandler(this, &EMPLEADOS::facBTN_Click);
			// 
			// cliBTN
			// 
			this->cliBTN->Location = System::Drawing::Point(213, 42);
			this->cliBTN->Name = L"cliBTN";
			this->cliBTN->Size = System::Drawing::Size(172, 26);
			this->cliBTN->TabIndex = 1;
			this->cliBTN->Text = L"CLIENTES";
			this->cliBTN->UseVisualStyleBackColor = true;
			this->cliBTN->Click += gcnew System::EventHandler(this, &EMPLEADOS::cliBTN_Click);
			// 
			// provBTN
			// 
			this->provBTN->Location = System::Drawing::Point(391, 43);
			this->provBTN->Name = L"provBTN";
			this->provBTN->Size = System::Drawing::Size(172, 25);
			this->provBTN->TabIndex = 2;
			this->provBTN->Text = L"PROVEEDORES";
			this->provBTN->UseVisualStyleBackColor = true;
			this->provBTN->Click += gcnew System::EventHandler(this, &EMPLEADOS::provBTN_Click);
			// 
			// stockBTN
			// 
			this->stockBTN->Location = System::Drawing::Point(569, 42);
			this->stockBTN->Name = L"stockBTN";
			this->stockBTN->Size = System::Drawing::Size(168, 26);
			this->stockBTN->TabIndex = 3;
			this->stockBTN->Text = L"STOCK";
			this->stockBTN->UseVisualStyleBackColor = true;
			this->stockBTN->Click += gcnew System::EventHandler(this, &EMPLEADOS::stockBTN_Click);
			// 
			// ingrBTN
			// 
			this->ingrBTN->Location = System::Drawing::Point(620, 212);
			this->ingrBTN->Name = L"ingrBTN";
			this->ingrBTN->Size = System::Drawing::Size(120, 29);
			this->ingrBTN->TabIndex = 4;
			this->ingrBTN->Text = L"INGRESAR";
			this->ingrBTN->UseVisualStyleBackColor = true;
			this->ingrBTN->Click += gcnew System::EventHandler(this, &EMPLEADOS::ingrBTN_Click);
			// 
			// eliBTN
			// 
			this->eliBTN->Location = System::Drawing::Point(620, 247);
			this->eliBTN->Name = L"eliBTN";
			this->eliBTN->Size = System::Drawing::Size(118, 25);
			this->eliBTN->TabIndex = 5;
			this->eliBTN->Text = L"ELIMINAR";
			this->eliBTN->UseVisualStyleBackColor = true;
			this->eliBTN->Click += gcnew System::EventHandler(this, &EMPLEADOS::eliBTN_Click);
			// 
			// modiBTN
			// 
			this->modiBTN->Location = System::Drawing::Point(620, 278);
			this->modiBTN->Name = L"modiBTN";
			this->modiBTN->Size = System::Drawing::Size(120, 25);
			this->modiBTN->TabIndex = 6;
			this->modiBTN->Text = L"MODIFICAR";
			this->modiBTN->UseVisualStyleBackColor = true;
			this->modiBTN->Click += gcnew System::EventHandler(this, &EMPLEADOS::modiBTN_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 91);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"DOCUMENTO";
			// 
			// idTBX
			// 
			this->idTBX->Location = System::Drawing::Point(35, 108);
			this->idTBX->Name = L"idTBX";
			this->idTBX->Size = System::Drawing::Size(253, 20);
			this->idTBX->TabIndex = 14;
			this->idTBX->TextChanged += gcnew System::EventHandler(this, &EMPLEADOS::idTBX_TextChanged);
			// 
			// table1
			// 
			this->table1->AllowUserToAddRows = false;
			this->table1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->table1->Location = System::Drawing::Point(12, 316);
			this->table1->Name = L"table1";
			this->table1->Size = System::Drawing::Size(762, 254);
			this->table1->TabIndex = 21;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 209);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 22;
			this->label2->Text = L"Hora_Entrada";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(32, 249);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 13);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Hora_Salida";
			// 
			// entrTBX
			// 
			this->entrTBX->Location = System::Drawing::Point(35, 226);
			this->entrTBX->Name = L"entrTBX";
			this->entrTBX->Size = System::Drawing::Size(250, 20);
			this->entrTBX->TabIndex = 24;
			this->entrTBX->TextChanged += gcnew System::EventHandler(this, &EMPLEADOS::entrTBX_TextChanged);
			// 
			// saliTBX
			// 
			this->saliTBX->Location = System::Drawing::Point(35, 265);
			this->saliTBX->Name = L"saliTBX";
			this->saliTBX->Size = System::Drawing::Size(250, 20);
			this->saliTBX->TabIndex = 25;
			this->saliTBX->TextChanged += gcnew System::EventHandler(this, &EMPLEADOS::saliTBX_TextChanged);
			// 
			// sueldoTBX
			// 
			this->sueldoTBX->Location = System::Drawing::Point(314, 226);
			this->sueldoTBX->Name = L"sueldoTBX";
			this->sueldoTBX->Size = System::Drawing::Size(242, 20);
			this->sueldoTBX->TabIndex = 26;
			this->sueldoTBX->TextChanged += gcnew System::EventHandler(this, &EMPLEADOS::sueldoTBX_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(314, 208);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 13);
			this->label4->TabIndex = 27;
			this->label4->Text = L"Sueldo";
			// 
			// buscarBTN
			// 
			this->buscarBTN->Location = System::Drawing::Point(620, 123);
			this->buscarBTN->Name = L"buscarBTN";
			this->buscarBTN->Size = System::Drawing::Size(118, 23);
			this->buscarBTN->TabIndex = 28;
			this->buscarBTN->Text = L"BUSCAR";
			this->buscarBTN->UseVisualStyleBackColor = true;
			this->buscarBTN->Click += gcnew System::EventHandler(this, &EMPLEADOS::buscarBTN_Click);
			// 
			// cerrarBTNEMP
			// 
			this->cerrarBTNEMP->Location = System::Drawing::Point(22, 12);
			this->cerrarBTNEMP->Name = L"cerrarBTNEMP";
			this->cerrarBTNEMP->Size = System::Drawing::Size(56, 24);
			this->cerrarBTNEMP->TabIndex = 29;
			this->cerrarBTNEMP->Text = L"Cerrar";
			this->cerrarBTNEMP->UseVisualStyleBackColor = true;
			this->cerrarBTNEMP->Click += gcnew System::EventHandler(this, &EMPLEADOS::cerrarBTNEMP_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(35, 135);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(54, 13);
			this->label7->TabIndex = 30;
			this->label7->Text = L"NOMBRE";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(314, 135);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(59, 13);
			this->label8->TabIndex = 31;
			this->label8->Text = L"APELLIDO";
			// 
			// nombreTBX
			// 
			this->nombreTBX->Location = System::Drawing::Point(35, 164);
			this->nombreTBX->Name = L"nombreTBX";
			this->nombreTBX->ReadOnly = true;
			this->nombreTBX->Size = System::Drawing::Size(250, 20);
			this->nombreTBX->TabIndex = 32;
			// 
			// apellidoTBX
			// 
			this->apellidoTBX->Location = System::Drawing::Point(317, 164);
			this->apellidoTBX->Name = L"apellidoTBX";
			this->apellidoTBX->ReadOnly = true;
			this->apellidoTBX->Size = System::Drawing::Size(239, 20);
			this->apellidoTBX->TabIndex = 33;
			// 
			// EMPLEADOS
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(795, 585);
			this->Controls->Add(this->apellidoTBX);
			this->Controls->Add(this->nombreTBX);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->cerrarBTNEMP);
			this->Controls->Add(this->buscarBTN);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->sueldoTBX);
			this->Controls->Add(this->saliTBX);
			this->Controls->Add(this->entrTBX);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->table1);
			this->Controls->Add(this->idTBX);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->modiBTN);
			this->Controls->Add(this->eliBTN);
			this->Controls->Add(this->ingrBTN);
			this->Controls->Add(this->stockBTN);
			this->Controls->Add(this->provBTN);
			this->Controls->Add(this->cliBTN);
			this->Controls->Add(this->facBTN);
			this->Name = L"EMPLEADOS";
			this->Text = L"EMPLEADOS";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void facBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void cliBTN_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void provBTN_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void stockBTN_Click(System::Object^ sender, System::EventArgs^ e);



	private: System::Void ingrBTN_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (idPersonaEncontrada == 0) {
				MessageBox::Show("Busque una persona primero con el boton BUSCAR");
				return;
			}

			std::string horaEntrada = msclr::interop::marshal_as<std::string>(entrTBX->Text);
			std::string horaSalida = msclr::interop::marshal_as<std::string>(saliTBX->Text);

			int sueldo = 0;
			if (!String::IsNullOrWhiteSpace(sueldoTBX->Text)) {
				sueldo = Int32::Parse(sueldoTBX->Text);
			}

			if (existeEmpleado(idPersonaEncontrada)) {
				MessageBox::Show("Empleado completo");
				return;
			}

			insertarEmpleado(idPersonaEncontrada, horaEntrada, horaSalida, sueldo);

			MessageBox::Show("Empleado registrado correctamente");

			idPersonaEncontrada = 0;
			idTBX->Text = L"";
			nombreTBX->Text = L"";
			apellidoTBX->Text = L"";
			entrTBX->Text = L"";
			saliTBX->Text = L"";
			sueldoTBX->Text = L"";

			cargarEmpleados(this->table1);
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void eliBTN_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (table1->SelectedRows->Count == 0) {
				MessageBox::Show("Seleccione un empleado de la tabla");
				return;
			}
			int idPersona = (int)table1->SelectedRows[0]->Cells["ID"]->Value;
			String^ rol = table1->SelectedRows[0]->Cells["Rol"]->Value->ToString();
			if (rol == "ADMINISTRADOR") {
				MessageBox::Show("No se puede eliminar un administrador");
				return;
			}
			auto result = MessageBox::Show("¿Deshabilitar este empleado?", "Confirmar", MessageBoxButtons::YesNo);
			if (result == System::Windows::Forms::DialogResult::Yes) {
				eliminarPersona(idPersona);
				cargarEmpleados(this->table1);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void modiBTN_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (!modoModificar) {
				if (table1->SelectedRows->Count == 0) {
					MessageBox::Show("Seleccione un empleado de la tabla");
					return;
				}
				DataGridViewRow^ row = table1->SelectedRows[0];
				idPersonaEncontrada = (int)row->Cells["ID"]->Value;
				nombreTBX->Text = row->Cells["Nombre"]->Value->ToString();
				apellidoTBX->Text = row->Cells["Apellido"]->Value->ToString();
				
				entrTBX->Text = row->Cells["HoraEntrada"]->Value->ToString();
				saliTBX->Text = row->Cells["HoraSalida"]->Value->ToString();
				sueldoTBX->Text = row->Cells["Sueldo"]->Value->ToString();
				modiBTN->Text = L"GUARDAR";
				modoModificar = true;
			} else {
				std::string horaEntrada = msclr::interop::marshal_as<std::string>(entrTBX->Text);
				std::string horaSalida = msclr::interop::marshal_as<std::string>(saliTBX->Text);
				int sueldo = 0;
				if (!String::IsNullOrWhiteSpace(sueldoTBX->Text)) {
					sueldo = Int32::Parse(sueldoTBX->Text);
				}
				modificarEmpleado(idPersonaEncontrada, horaEntrada, horaSalida, sueldo);
				//MessageBox::Show("Empleado modificado correctamente");
				modiBTN->Text = L"MODIFICAR";
				modoModificar = false;
				idPersonaEncontrada = 0;
				idTBX->Text = L"";
				nombreTBX->Text = L"";
				apellidoTBX->Text = L"";
				entrTBX->Text = L"";
				saliTBX->Text = L"";
				sueldoTBX->Text = L"";
				cargarEmpleados(this->table1);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}



	private: System::Void idTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	
	private: System::Void entrTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void saliTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void sueldoTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}


	private: System::Void cerrarBTNEMP_Click(System::Object^ sender, System::EventArgs^ e); 
	


private: System::Void buscarBTN_Click(System::Object^ sender, System::EventArgs^ e) {

	try {
		std::string documento = msclr::interop::marshal_as<std::string>(idTBX->Text);
		if (documento.empty()) {
			MessageBox::Show("Ingrese un numero de documento");
			return;
		}

		std::string nombre, apellido;
		idPersonaEncontrada = buscarPersonaPorDocumento(documento, nombre, apellido);

		if (idPersonaEncontrada == 0) {
			MessageBox::Show("Persona no encontrada para ese documento");
			nombreTBX->Text = L"";
			apellidoTBX->Text = L"";
			return;
		}

		nombreTBX->Text = gcnew String(nombre.c_str());
		apellidoTBX->Text = gcnew String(apellido.c_str());
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
	}
}

};



}
