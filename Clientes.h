#pragma once
#include "peliVAR.h"

#include <msclr/marshal_cppstd.h>
using namespace  std;
ref class EMPLEADOS;
ref class STOCK;
void cargarClientes(System::Windows::Forms::DataGridView^ grid);
void eliminarCliente(int idPersona);
void modificarCliente(int idPersona,
    const std::string& nombre, const std::string& apellido, const std::string& password,
    const std::string& nroDocumento, const std::string& tipoDocumento,
    const std::string& correo, const std::string& telefono,
    const std::string& calle, const std::string& numero, const std::string& ciudad);
int insertarCliente(const std::string& nombre, const std::string& apellido, const std::string& password,
    const std::string& nroDocumento, const std::string& tipoDocumento,
    const std::string& correo, const std::string& telefono,
    const std::string& calle, const std::string& numero, const std::string& ciudad);
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
	public ref class CLIENTES : public System::Windows::Forms::Form
	{
	private: bool modoModificar;
	public:
		CLIENTES(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
			modoModificar = false;

			this->idpersonaTBX->ReadOnly = true;

			cli::array<System::Object^>^ tipoItems = {
				L"ELEGIR:",
				L"DNI",
				L"CUIL",
				L"Pasaporte Electronico"
			};
			this->tipoCb->Items->AddRange(tipoItems);
			this->tipoCb->SelectedIndex = 0;
			this->tipoCb->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

			this->rolTBX->Text = L"CLIENTE";
			this->rolTBX->ReadOnly = true;

			cargarClientes(this->table1);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~CLIENTES()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ facBTN;
	private: System::Windows::Forms::Button^ stockBTN;

	private: System::Windows::Forms::Button^ provBTN;

	private: System::Windows::Forms::Button^ ingrBTN;


	private: System::Windows::Forms::Button^ eliBTN;

	private: System::Windows::Forms::Button^ modiBTN;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ idpersonaTBX;


	private: System::Windows::Forms::TextBox^ nomTBX;
	private: System::Windows::Forms::TextBox^ apeTBX;
	private: System::Windows::Forms::TextBox^ telTBX;
	private: System::Windows::Forms::TextBox^ gmailTBX;










	private: System::Windows::Forms::DataGridView^ table1;
	private: System::Windows::Forms::Button^ emplBTN;
	private: System::Windows::Forms::TextBox^ passTBX;

	private: System::Windows::Forms::TextBox^ rolTBX;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ calleTBX;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ documentoTXB;
	private: System::Windows::Forms::ComboBox^ tipoCb;


	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ numeroTBX;
	private: System::Windows::Forms::TextBox^ ciudadTBX;




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
			this->stockBTN = (gcnew System::Windows::Forms::Button());
			this->provBTN = (gcnew System::Windows::Forms::Button());
			this->ingrBTN = (gcnew System::Windows::Forms::Button());
			this->eliBTN = (gcnew System::Windows::Forms::Button());
			this->modiBTN = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->idpersonaTBX = (gcnew System::Windows::Forms::TextBox());
			this->nomTBX = (gcnew System::Windows::Forms::TextBox());
			this->apeTBX = (gcnew System::Windows::Forms::TextBox());
			this->telTBX = (gcnew System::Windows::Forms::TextBox());
			this->gmailTBX = (gcnew System::Windows::Forms::TextBox());
			this->table1 = (gcnew System::Windows::Forms::DataGridView());
			this->emplBTN = (gcnew System::Windows::Forms::Button());
			this->passTBX = (gcnew System::Windows::Forms::TextBox());
			this->rolTBX = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->calleTBX = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->documentoTXB = (gcnew System::Windows::Forms::TextBox());
			this->tipoCb = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->numeroTBX = (gcnew System::Windows::Forms::TextBox());
			this->ciudadTBX = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table1))->BeginInit();
			this->SuspendLayout();
			// 
			// facBTN
			// 
			this->facBTN->Location = System::Drawing::Point(35, 28);
			this->facBTN->Name = L"facBTN";
			this->facBTN->Size = System::Drawing::Size(172, 26);
			this->facBTN->TabIndex = 0;
			this->facBTN->Text = L"FACTURACION";
			this->facBTN->UseVisualStyleBackColor = true;
			this->facBTN->Click += gcnew System::EventHandler(this, &CLIENTES::facBTN_Click);
			// 
			// stockBTN
			// 
			this->stockBTN->Location = System::Drawing::Point(569, 28);
			this->stockBTN->Name = L"stockBTN";
			this->stockBTN->Size = System::Drawing::Size(172, 26);
			this->stockBTN->TabIndex = 1;
			this->stockBTN->Text = L"STOCK";
			this->stockBTN->UseVisualStyleBackColor = true;
			this->stockBTN->Click += gcnew System::EventHandler(this, &CLIENTES::stockBTN_Click);
			// 
			// provBTN
			// 
			this->provBTN->Location = System::Drawing::Point(382, 29);
			this->provBTN->Name = L"provBTN";
			this->provBTN->Size = System::Drawing::Size(181, 25);
			this->provBTN->TabIndex = 2;
			this->provBTN->Text = L"PROVEEDORES";
			this->provBTN->UseVisualStyleBackColor = true;
			this->provBTN->Click += gcnew System::EventHandler(this, &CLIENTES::provBTN_Click);
			// 
			// ingrBTN
			// 
			this->ingrBTN->Location = System::Drawing::Point(627, 196);
			this->ingrBTN->Name = L"ingrBTN";
			this->ingrBTN->Size = System::Drawing::Size(120, 29);
			this->ingrBTN->TabIndex = 4;
			this->ingrBTN->Text = L"INGRESAR";
			this->ingrBTN->UseVisualStyleBackColor = true;
			this->ingrBTN->Click += gcnew System::EventHandler(this, &CLIENTES::ingrBTN_Click);
			// 
			// eliBTN
			// 
			this->eliBTN->Location = System::Drawing::Point(627, 231);
			this->eliBTN->Name = L"eliBTN";
			this->eliBTN->Size = System::Drawing::Size(118, 25);
			this->eliBTN->TabIndex = 5;
			this->eliBTN->Text = L"ELIMINAR";
			this->eliBTN->UseVisualStyleBackColor = true;
			this->eliBTN->Click += gcnew System::EventHandler(this, &CLIENTES::eliBTN_Click);
			// 
			// modiBTN
			// 
			this->modiBTN->Location = System::Drawing::Point(627, 262);
			this->modiBTN->Name = L"modiBTN";
			this->modiBTN->Size = System::Drawing::Size(120, 25);
			this->modiBTN->TabIndex = 6;
			this->modiBTN->Text = L"MODIFICAR";
			this->modiBTN->UseVisualStyleBackColor = true;
			this->modiBTN->Click += gcnew System::EventHandler(this, &CLIENTES::modiBTN_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(36, 76);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"ID_PERSONA";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(36, 126);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"NOMBRE";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(36, 174);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"APELLIDO";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(36, 213);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"TELEFONO";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(307, 81);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"GMAIL";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(307, 127);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"PASSWORD";
			// 
			// idpersonaTBX
			// 
			this->idpersonaTBX->Location = System::Drawing::Point(39, 93);
			this->idpersonaTBX->Name = L"idpersonaTBX";
			this->idpersonaTBX->Size = System::Drawing::Size(253, 20);
			this->idpersonaTBX->TabIndex = 14;
			this->idpersonaTBX->TextChanged += gcnew System::EventHandler(this, &CLIENTES::idpersonaTBX_TextChanged);
			// 
			// nomTBX
			// 
			this->nomTBX->Location = System::Drawing::Point(39, 142);
			this->nomTBX->Name = L"nomTBX";
			this->nomTBX->Size = System::Drawing::Size(253, 20);
			this->nomTBX->TabIndex = 15;
			this->nomTBX->TextChanged += gcnew System::EventHandler(this, &CLIENTES::nomTBX_TextChanged);
			// 
			// apeTBX
			// 
			this->apeTBX->Location = System::Drawing::Point(39, 190);
			this->apeTBX->Name = L"apeTBX";
			this->apeTBX->Size = System::Drawing::Size(253, 20);
			this->apeTBX->TabIndex = 16;
			this->apeTBX->TextChanged += gcnew System::EventHandler(this, &CLIENTES::apeTBX_TextChanged);
			// 
			// telTBX
			// 
			this->telTBX->Location = System::Drawing::Point(39, 232);
			this->telTBX->Name = L"telTBX";
			this->telTBX->Size = System::Drawing::Size(253, 20);
			this->telTBX->TabIndex = 17;
			this->telTBX->TextChanged += gcnew System::EventHandler(this, &CLIENTES::telTBX_TextChanged);
			// 
			// gmailTBX
			// 
			this->gmailTBX->Location = System::Drawing::Point(310, 97);
			this->gmailTBX->Name = L"gmailTBX";
			this->gmailTBX->Size = System::Drawing::Size(253, 20);
			this->gmailTBX->TabIndex = 18;
			this->gmailTBX->TextChanged += gcnew System::EventHandler(this, &CLIENTES::gmailTBX_TextChanged);
			// 
			// table1
			// 
			this->table1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->table1->Location = System::Drawing::Point(12, 385);
			this->table1->Name = L"table1";
			this->table1->Size = System::Drawing::Size(823, 247);
			this->table1->TabIndex = 21;
			// 
			// emplBTN
			// 
			this->emplBTN->Location = System::Drawing::Point(213, 29);
			this->emplBTN->Name = L"emplBTN";
			this->emplBTN->Size = System::Drawing::Size(163, 24);
			this->emplBTN->TabIndex = 23;
			this->emplBTN->Text = L"EMPLEADOS";
			this->emplBTN->UseVisualStyleBackColor = true;
			this->emplBTN->Click += gcnew System::EventHandler(this, &CLIENTES::emplBTN_Click);
			// 
			// passTBX
			// 
			this->passTBX->Location = System::Drawing::Point(310, 143);
			this->passTBX->Name = L"passTBX";
			this->passTBX->Size = System::Drawing::Size(253, 20);
			this->passTBX->TabIndex = 19;
			this->passTBX->TextChanged += gcnew System::EventHandler(this, &CLIENTES::passTBX_TextChanged);
			// 
			// rolTBX
			// 
			this->rolTBX->Location = System::Drawing::Point(310, 328);
			this->rolTBX->Name = L"rolTBX";
			this->rolTBX->Size = System::Drawing::Size(253, 20);
			this->rolTBX->TabIndex = 24;
			this->rolTBX->TextChanged += gcnew System::EventHandler(this, &CLIENTES::rolTBX_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(310, 312);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(29, 13);
			this->label7->TabIndex = 25;
			this->label7->Text = L"ROL";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(36, 259);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(66, 13);
			this->label8->TabIndex = 26;
			this->label8->Text = L"DIRECCION";
			// 
			// calleTBX
			// 
			this->calleTBX->Location = System::Drawing::Point(39, 276);
			this->calleTBX->Name = L"calleTBX";
			this->calleTBX->Size = System::Drawing::Size(250, 20);
			this->calleTBX->TabIndex = 27;
			this->calleTBX->TextChanged += gcnew System::EventHandler(this, &CLIENTES::calleTBX_TextChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(307, 170);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(77, 13);
			this->label9->TabIndex = 28;
			this->label9->Text = L"DOCUMENTO";
			// 
			// documentoTXB
			// 
			this->documentoTXB->Location = System::Drawing::Point(310, 186);
			this->documentoTXB->Name = L"documentoTXB";
			this->documentoTXB->Size = System::Drawing::Size(250, 20);
			this->documentoTXB->TabIndex = 29;
			// 
			// tipoCb
			// 
			this->tipoCb->FormattingEnabled = true;
			this->tipoCb->Location = System::Drawing::Point(310, 231);
			this->tipoCb->Name = L"tipoCb";
			this->tipoCb->Size = System::Drawing::Size(253, 21);
			this->tipoCb->TabIndex = 30;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(307, 214);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(32, 13);
			this->label10->TabIndex = 31;
			this->label10->Text = L"TIPO";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(36, 312);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(55, 13);
			this->label11->TabIndex = 32;
			this->label11->Text = L"NUMERO";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(307, 259);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(48, 13);
			this->label12->TabIndex = 33;
			this->label12->Text = L"CIUDAD";
			// 
			// numeroTBX
			// 
			this->numeroTBX->Location = System::Drawing::Point(39, 328);
			this->numeroTBX->Name = L"numeroTBX";
			this->numeroTBX->Size = System::Drawing::Size(250, 20);
			this->numeroTBX->TabIndex = 34;
			this->numeroTBX->TextChanged += gcnew System::EventHandler(this, &CLIENTES::numeroTBX_TextChanged);
			// 
			// ciudadTBX
			// 
			this->ciudadTBX->Location = System::Drawing::Point(310, 275);
			this->ciudadTBX->Name = L"ciudadTBX";
			this->ciudadTBX->Size = System::Drawing::Size(253, 20);
			this->ciudadTBX->TabIndex = 35;
			this->ciudadTBX->TextChanged += gcnew System::EventHandler(this, &CLIENTES::ciudadTBX_TextChanged);
			// 
			// CLIENTES
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(847, 644);
			this->Controls->Add(this->ciudadTBX);
			this->Controls->Add(this->numeroTBX);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->tipoCb);
			this->Controls->Add(this->documentoTXB);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->calleTBX);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->rolTBX);
			this->Controls->Add(this->emplBTN);
			this->Controls->Add(this->table1);
			this->Controls->Add(this->passTBX);
			this->Controls->Add(this->gmailTBX);
			this->Controls->Add(this->telTBX);
			this->Controls->Add(this->apeTBX);
			this->Controls->Add(this->nomTBX);
			this->Controls->Add(this->idpersonaTBX);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->modiBTN);
			this->Controls->Add(this->eliBTN);
			this->Controls->Add(this->ingrBTN);
			this->Controls->Add(this->provBTN);
			this->Controls->Add(this->stockBTN);
			this->Controls->Add(this->facBTN);

			this->table1->AllowUserToAddRows = false;
			this->Name = L"CLIENTES";
			this->Text = L"CLIENTES";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void facBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void stockBTN_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void provBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void emplBTN_Click(System::Object^ sender, System::EventArgs^ e);


	private: System::Void ingrBTN_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (tipoCb->SelectedIndex == 0) {
				MessageBox::Show("Seleccione un tipo de documento valido");
				return;
			}

			if (String::IsNullOrWhiteSpace(nomTBX->Text) ||
				String::IsNullOrWhiteSpace(apeTBX->Text) ||
				String::IsNullOrWhiteSpace(passTBX->Text) ||
				String::IsNullOrWhiteSpace(documentoTXB->Text) ||
				String::IsNullOrWhiteSpace(gmailTBX->Text) ||
				String::IsNullOrWhiteSpace(telTBX->Text) ||
				String::IsNullOrWhiteSpace(calleTBX->Text) ||
				String::IsNullOrWhiteSpace(numeroTBX->Text) ||
				String::IsNullOrWhiteSpace(ciudadTBX->Text)) {
				MessageBox::Show("Complete todos los campos");
				return;
			}

			std::string nombre = msclr::interop::marshal_as<std::string>(nomTBX->Text);
			std::string apellido = msclr::interop::marshal_as<std::string>(apeTBX->Text);
			std::string password = msclr::interop::marshal_as<std::string>(passTBX->Text);
			std::string nroDocumento = msclr::interop::marshal_as<std::string>(documentoTXB->Text);
			std::string tipoDocumento = msclr::interop::marshal_as<std::string>(tipoCb->Text);
			std::string correo = msclr::interop::marshal_as<std::string>(gmailTBX->Text);
			std::string telefono = msclr::interop::marshal_as<std::string>(telTBX->Text);
			std::string calle = msclr::interop::marshal_as<std::string>(calleTBX->Text);
			std::string numero = msclr::interop::marshal_as<std::string>(numeroTBX->Text);
			std::string ciudad = msclr::interop::marshal_as<std::string>(ciudadTBX->Text);

			int id = insertarCliente(nombre, apellido, password, nroDocumento, tipoDocumento, correo, telefono, calle, numero, ciudad);
			if (id == 0) return;

			MessageBox::Show("Cliente registrado correctamente");

			nomTBX->Text = L"";
			apeTBX->Text = L"";
			passTBX->Text = L"";
			documentoTXB->Text = L"";
			tipoCb->SelectedIndex = 0;
			gmailTBX->Text = L"";
			telTBX->Text = L"";
			calleTBX->Text = L"";
			numeroTBX->Text = L"";
			ciudadTBX->Text = L"";
			idpersonaTBX->Text = L"";

			cargarClientes(this->table1);
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void eliBTN_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (table1->SelectedRows->Count == 0) {
				MessageBox::Show("Seleccione un cliente de la tabla");
				return;
			}
			int idPersona = (int)table1->SelectedRows[0]->Cells["ID"]->Value;
			/* auto result = MessageBox::Show("Deshabilitar este cliente?", "Confirmar", MessageBoxButtons::YesNo);
			if (result == System::Windows::Forms::DialogResult::Yes) {}*/
				eliminarCliente(idPersona);
				cargarClientes(this->table1);
			
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void modiBTN_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (!modoModificar) {
				if (table1->SelectedRows->Count == 0) {
					MessageBox::Show("Seleccione un cliente de la tabla");
					return;
				}
				DataGridViewRow^ row = table1->SelectedRows[0];
				idpersonaTBX->Text = row->Cells["ID"]->Value->ToString();
				nomTBX->Text = row->Cells["Nombre"]->Value->ToString();
				apeTBX->Text = row->Cells["Apellido"]->Value->ToString();
				passTBX->Text = row->Cells["Password"]->Value->ToString();
				documentoTXB->Text = row->Cells["NumDocumento"]->Value->ToString();
				gmailTBX->Text = row->Cells["Email"]->Value->ToString();
				telTBX->Text = row->Cells["Telefono"]->Value->ToString();
				calleTBX->Text = row->Cells["Calle"]->Value->ToString();
				numeroTBX->Text = row->Cells["Numero"]->Value->ToString();
				ciudadTBX->Text = row->Cells["Ciudad"]->Value->ToString();
				String^ tipoDoc = row->Cells["TipoDocumento"]->Value->ToString();
				for (int i = 0; i < tipoCb->Items->Count; i++) {
					if (tipoCb->Items[i]->ToString() == tipoDoc) {
						tipoCb->SelectedIndex = i;
						break;
					}
				}
				modiBTN->Text = L"GUARDAR";
				modoModificar = true;
			} else {
				if (tipoCb->SelectedIndex == 0) {
					MessageBox::Show("Seleccione un tipo de documento valido");
					return;
				}
				if (String::IsNullOrWhiteSpace(nomTBX->Text) ||
					String::IsNullOrWhiteSpace(apeTBX->Text) ||
					String::IsNullOrWhiteSpace(passTBX->Text) ||
					String::IsNullOrWhiteSpace(documentoTXB->Text) ||
					String::IsNullOrWhiteSpace(gmailTBX->Text) ||
					String::IsNullOrWhiteSpace(telTBX->Text) ||
					String::IsNullOrWhiteSpace(calleTBX->Text) ||
					String::IsNullOrWhiteSpace(numeroTBX->Text) ||
					String::IsNullOrWhiteSpace(ciudadTBX->Text)) {
					MessageBox::Show("Complete todos los campos");
					return;
				}
				int idPersona = Int32::Parse(idpersonaTBX->Text);
				std::string nombre = msclr::interop::marshal_as<std::string>(nomTBX->Text);
				std::string apellido = msclr::interop::marshal_as<std::string>(apeTBX->Text);
				std::string password = msclr::interop::marshal_as<std::string>(passTBX->Text);
				std::string nroDocumento = msclr::interop::marshal_as<std::string>(documentoTXB->Text);
				std::string tipoDocumento = msclr::interop::marshal_as<std::string>(tipoCb->Text);
				std::string correo = msclr::interop::marshal_as<std::string>(gmailTBX->Text);
				std::string telefono = msclr::interop::marshal_as<std::string>(telTBX->Text);
				std::string calleStr = msclr::interop::marshal_as<std::string>(calleTBX->Text);
				std::string numeroStr = msclr::interop::marshal_as<std::string>(numeroTBX->Text);
				std::string ciudadStr = msclr::interop::marshal_as<std::string>(ciudadTBX->Text);
				modificarCliente(idPersona, nombre, apellido, password, nroDocumento, tipoDocumento,
					correo, telefono, calleStr, numeroStr, ciudadStr);
				MessageBox::Show("Cliente modificado correctamente");
				modiBTN->Text = L"MODIFICAR";
				modoModificar = false;
				nomTBX->Text = L"";
				apeTBX->Text = L"";
				passTBX->Text = L"";
				documentoTXB->Text = L"";
				tipoCb->SelectedIndex = 0;
				gmailTBX->Text = L"";
				telTBX->Text = L"";
				calleTBX->Text = L"";
				numeroTBX->Text = L"";
				ciudadTBX->Text = L"";
				idpersonaTBX->Text = L"";
				
				cargarClientes(this->table1);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}



	

	private: System::Void nomTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void apeTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void telTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void gmailTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void passTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void rolTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	
private: System::Void calleTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ciudadTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}


private: System::Void numeroTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void idpersonaTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};



}
