#pragma once
#include "peliVAR.h"
ref class Login;
void cargarAdministradores(System::Windows::Forms::DataGridView^ grid);
void modificarPersonaCompleta(int idPersona, const std::string& nombre, const std::string& apellido,
    const std::string& password, const std::string& rol,
    const std::string& numeroDocumento, const std::string& tipoDocumento,
    const std::string& correo, const std::string& telefono,
    const std::string& calle, const std::string& numero, const std::string& ciudad);

#include <msclr/marshal_cppstd.h>

/*Faltaria la funcion*/
namespace FACPelisVistas {
	//  INSERTtableCon
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Registrar
	/// </summary>
	public ref class Registrar : public System::Windows::Forms::Form
	{
	public:
		Registrar(void)
		{
		InitializeComponent();
		//
		//TODO: agregar c�digo de constructor aqu�
		//
		cli::array<System::Object^>^ tipoItems = {
			L"ELEGIR:",
			L"DNI",
			L"CUIL",
			L"Pasaporte Electronico"
		};

		this->tipoCBOX->Items->AddRange(tipoItems);
		this->tipoCBOX->SelectedIndex = 0;

		this->tipoCBOX->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

		cli::array<System::Object^>^ ROL = {
			L"ELEGIR:",
			L"CLIENTE",
			L"EMPLEADO",
			L"ADMINISTRADOR"
		};

		this->rolCBOX->Items->AddRange(ROL);
		this->rolCBOX->SelectedIndex = 0;

		this->rolCBOX->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

		cargarAdministradores(dataGridView1);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~Registrar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ regBTN;
	private: System::Windows::Forms::Button^ atrBTN;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ nomTBX;
	private: System::Windows::Forms::TextBox^ apeTBX;
	private: System::Windows::Forms::TextBox^ telefTBX;

		  

	private: System::Windows::Forms::TextBox^ emailTBX;


	private: System::Windows::Forms::TextBox^ passTBX;



	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ NumDoTBX;



	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ calleTBX;
	private: System::Windows::Forms::TextBox^ numCTBX;



	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ ciudTBX;



	private: System::Windows::Forms::Label^ label12;

	private: System::Windows::Forms::ComboBox^ tipoCBOX;
	private: System::Windows::Forms::ComboBox^ rolCBOX;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ modificarTBX;
	private: System::Windows::Forms::Label^ idp;
	private: System::Windows::Forms::TextBox^ idpersonaTBX;




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
			this->regBTN = (gcnew System::Windows::Forms::Button());
			this->atrBTN = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->nomTBX = (gcnew System::Windows::Forms::TextBox());
			this->apeTBX = (gcnew System::Windows::Forms::TextBox());
			this->telefTBX = (gcnew System::Windows::Forms::TextBox());
			this->emailTBX = (gcnew System::Windows::Forms::TextBox());
			this->passTBX = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->NumDoTBX = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->calleTBX = (gcnew System::Windows::Forms::TextBox());
			this->numCTBX = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->ciudTBX = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->tipoCBOX = (gcnew System::Windows::Forms::ComboBox());
			this->rolCBOX = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->modificarTBX = (gcnew System::Windows::Forms::Button());
			this->idp = (gcnew System::Windows::Forms::Label());
			this->idpersonaTBX = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// regBTN
			// 
			this->regBTN->Location = System::Drawing::Point(27, 379);
			this->regBTN->Name = L"regBTN";
			this->regBTN->Size = System::Drawing::Size(350, 23);
			this->regBTN->TabIndex = 0;
			this->regBTN->Text = L"Registrar";
			this->regBTN->UseVisualStyleBackColor = true;
			this->regBTN->Click += gcnew System::EventHandler(this, &Registrar::regBTN_Click);
			// 
			// atrBTN
			// 
			this->atrBTN->Location = System::Drawing::Point(544, 379);
			this->atrBTN->Name = L"atrBTN";
			this->atrBTN->Size = System::Drawing::Size(153, 23);
			this->atrBTN->TabIndex = 1;
			this->atrBTN->Text = L"Atras";
			this->atrBTN->UseVisualStyleBackColor = true;
			this->atrBTN->Click += gcnew System::EventHandler(this, &Registrar::atrBTN_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(31, 83);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Nombre";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(31, 122);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Apellido";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 335);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Telefono";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(31, 291);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(32, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Email";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(31, 166);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Password";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(31, 201);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(23, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Rol";
			// 
			// nomTBX
			// 
			this->nomTBX->Location = System::Drawing::Point(28, 99);
			this->nomTBX->Name = L"nomTBX";
			this->nomTBX->Size = System::Drawing::Size(315, 20);
			this->nomTBX->TabIndex = 8;
			// 
			// apeTBX
			// 
			this->apeTBX->Location = System::Drawing::Point(28, 138);
			this->apeTBX->Name = L"apeTBX";
			this->apeTBX->Size = System::Drawing::Size(315, 20);
			this->apeTBX->TabIndex = 9;
			// 
			// telefTBX
			// 
			this->telefTBX->Location = System::Drawing::Point(28, 351);
			this->telefTBX->Name = L"telefTBX";
			this->telefTBX->Size = System::Drawing::Size(315, 20);
			this->telefTBX->TabIndex = 10;
			// 
			// emailTBX
			// 
			this->emailTBX->Location = System::Drawing::Point(28, 309);
			this->emailTBX->Name = L"emailTBX";
			this->emailTBX->Size = System::Drawing::Size(315, 20);
			this->emailTBX->TabIndex = 11;
			// 
			// passTBX
			// 
			this->passTBX->Location = System::Drawing::Point(28, 182);
			this->passTBX->Name = L"passTBX";
			this->passTBX->Size = System::Drawing::Size(315, 20);
			this->passTBX->TabIndex = 12;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(337, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(70, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"RESGITRAR";
			// 
			// NumDoTBX
			// 
			this->NumDoTBX->Location = System::Drawing::Point(383, 99);
			this->NumDoTBX->Name = L"NumDoTBX";
			this->NumDoTBX->Size = System::Drawing::Size(315, 20);
			this->NumDoTBX->TabIndex = 15;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(380, 83);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(99, 13);
			this->label8->TabIndex = 17;
			this->label8->Text = L"NumeroDocumento";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(380, 123);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(83, 13);
			this->label9->TabIndex = 18;
			this->label9->Text = L"TipoDocumento";
			// 
			// calleTBX
			// 
			this->calleTBX->Location = System::Drawing::Point(383, 221);
			this->calleTBX->Name = L"calleTBX";
			this->calleTBX->Size = System::Drawing::Size(315, 20);
			this->calleTBX->TabIndex = 22;
			// 
			// numCTBX
			// 
			this->numCTBX->Location = System::Drawing::Point(383, 263);
			this->numCTBX->Name = L"numCTBX";
			this->numCTBX->Size = System::Drawing::Size(315, 20);
			this->numCTBX->TabIndex = 21;
			this->numCTBX->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registrar::numCTBX_KeyPress);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(380, 205);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(30, 13);
			this->label10->TabIndex = 20;
			this->label10->Text = L"Calle";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(380, 247);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(44, 13);
			this->label11->TabIndex = 19;
			this->label11->Text = L"Numero";
			// 
			// ciudTBX
			// 
			this->ciudTBX->Location = System::Drawing::Point(383, 309);
			this->ciudTBX->Name = L"ciudTBX";
			this->ciudTBX->Size = System::Drawing::Size(315, 20);
			this->ciudTBX->TabIndex = 26;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(380, 293);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(40, 13);
			this->label12->TabIndex = 24;
			this->label12->Text = L"Ciudad";
			// 
			// tipoCBOX
			// 
			this->tipoCBOX->FormattingEnabled = true;
			this->tipoCBOX->Location = System::Drawing::Point(383, 139);
			this->tipoCBOX->Name = L"tipoCBOX";
			this->tipoCBOX->Size = System::Drawing::Size(315, 21);
			this->tipoCBOX->TabIndex = 27;
			// 
			// rolCBOX
			// 
			this->rolCBOX->FormattingEnabled = true;
			this->rolCBOX->Location = System::Drawing::Point(28, 221);
			this->rolCBOX->Name = L"rolCBOX";
			this->rolCBOX->Size = System::Drawing::Size(315, 21);
			this->rolCBOX->TabIndex = 28;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 423);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(743, 154);
			this->dataGridView1->TabIndex = 29;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Registrar::dataGridView1_CellClick);
			// 
			// modificarTBX
			// 
			this->modificarTBX->Location = System::Drawing::Point(383, 380);
			this->modificarTBX->Name = L"modificarTBX";
			this->modificarTBX->Size = System::Drawing::Size(155, 22);
			this->modificarTBX->TabIndex = 30;
			this->modificarTBX->Text = L"Modificar";
			this->modificarTBX->UseVisualStyleBackColor = true;
			this->modificarTBX->Click += gcnew System::EventHandler(this, &Registrar::modificarTBX_Click);
			// 
			// idp
			// 
			this->idp->AutoSize = true;
			this->idp->Location = System::Drawing::Point(31, 38);
			this->idp->Name = L"idp";
			this->idp->Size = System::Drawing::Size(76, 13);
			this->idp->TabIndex = 31;
			this->idp->Text = L"ID_PERSONA";
			// 
			// idpersonaTBX
			// 
			this->idpersonaTBX->Location = System::Drawing::Point(28, 54);
			this->idpersonaTBX->Name = L"idpersonaTBX";
			this->idpersonaTBX->Size = System::Drawing::Size(315, 20);
			this->idpersonaTBX->TabIndex = 32;
			this->idpersonaTBX->ReadOnly = true;
			// 
			// Registrar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(767, 589);
			this->Controls->Add(this->idpersonaTBX);
			this->Controls->Add(this->idp);
			this->Controls->Add(this->modificarTBX);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->rolCBOX);
			this->Controls->Add(this->ciudTBX);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->calleTBX);
			this->Controls->Add(this->numCTBX);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->tipoCBOX);
			this->Controls->Add(this->NumDoTBX);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->passTBX);
			this->Controls->Add(this->emailTBX);
			this->Controls->Add(this->telefTBX);
			this->Controls->Add(this->apeTBX);
			this->Controls->Add(this->nomTBX);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->atrBTN);
			this->Controls->Add(this->regBTN);
			this->Name = L"Registrar";
			this->Text = L"Registrar";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void regBTN_Click(System::Object^ sender, System::EventArgs^ e) {

		if (dataGridView1->SelectedRows->Count > 0) {
			MessageBox::Show("Termine de modificar");
			return;
		}

		if (tipoCBOX->SelectedIndex == 0 || rolCBOX->SelectedIndex == 0) {
			MessageBox::Show("Seleccione un tipo de documento y un rol validos");
			return;
		}

		if (String::IsNullOrWhiteSpace(nomTBX->Text) || String::IsNullOrWhiteSpace(apeTBX->Text) ||
			String::IsNullOrWhiteSpace(passTBX->Text) || String::IsNullOrWhiteSpace(emailTBX->Text) ||
			String::IsNullOrWhiteSpace(telefTBX->Text) || String::IsNullOrWhiteSpace(NumDoTBX->Text) ||
			String::IsNullOrWhiteSpace(calleTBX->Text) || String::IsNullOrWhiteSpace(numCTBX->Text) ||
			String::IsNullOrWhiteSpace(ciudTBX->Text)) {
			MessageBox::Show("Todos los campos deben estar completos");
			return;
		}

		try {

			std::string nombre =
				msclr::interop::marshal_as<std::string>(nomTBX->Text);

			std::string apellido =
				msclr::interop::marshal_as<std::string>(apeTBX->Text);

			std::string password =
				msclr::interop::marshal_as<std::string>(passTBX->Text);

			std::string rol =
				msclr::interop::marshal_as<std::string>(rolCBOX->Text);

			std::string numeroDocumento =
				msclr::interop::marshal_as<std::string>(NumDoTBX->Text);

			std::string tipoDocumento =
				msclr::interop::marshal_as<std::string>(tipoCBOX->Text);

			std::string correo =
				msclr::interop::marshal_as<std::string>(emailTBX->Text);

			std::string telefono =
				msclr::interop::marshal_as<std::string>(telefTBX->Text);

			std::string calle =
				msclr::interop::marshal_as<std::string>(calleTBX->Text);

			std::string numero =
				msclr::interop::marshal_as<std::string>(numCTBX->Text);

			std::string ciudad =
				msclr::interop::marshal_as<std::string>(ciudTBX->Text);

			conexionCls* con = new conexionCls(
				nombre,
				apellido,
				password,
				rol,
				numeroDocumento,
				tipoDocumento,
				correo,
				telefono,
				calle,
				numero,
				ciudad
			);

			con->conectVoid();
			con->insertarPersona();

			delete con;

			//MessageBox::Show("Persona registrada");

			nomTBX->Text = L"";
			apeTBX->Text = L"";
			passTBX->Text = L"";
			rolCBOX->SelectedIndex = 0;
			NumDoTBX->Text = L"";
			tipoCBOX->SelectedIndex = 0;
			emailTBX->Text = L"";
			telefTBX->Text = L"";
			calleTBX->Text = L"";
			numCTBX->Text = L"";
			ciudTBX->Text = L"";
		

		}
		catch (Exception^ ex) {

			MessageBox::Show(ex->Message);

		}
	}
	private: System::Void atrBTN_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void modificarTBX_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (dataGridView1->SelectedRows->Count == 0) {
				MessageBox::Show("Seleccione una persona de la tabla");
				return;
			}
			if (tipoCBOX->SelectedIndex == 0 || rolCBOX->SelectedIndex == 0) {
				MessageBox::Show("Seleccione un tipo de documento y un rol validos");
				return;
			}
			if (String::IsNullOrWhiteSpace(nomTBX->Text) || String::IsNullOrWhiteSpace(apeTBX->Text) ||
				String::IsNullOrWhiteSpace(passTBX->Text) || String::IsNullOrWhiteSpace(emailTBX->Text) ||
				String::IsNullOrWhiteSpace(telefTBX->Text) || String::IsNullOrWhiteSpace(NumDoTBX->Text) ||
				String::IsNullOrWhiteSpace(calleTBX->Text) || String::IsNullOrWhiteSpace(numCTBX->Text) ||
				String::IsNullOrWhiteSpace(ciudTBX->Text)) {
				MessageBox::Show("Todos los campos deben estar completos");
				return;
			}
			int idPersona = Int32::Parse(idpersonaTBX->Text);
			String^ rolActual = (String^)dataGridView1->SelectedRows[0]->Cells["Rol"]->Value;
			if (String::Compare(rolActual, "ADMINISTRADOR", true) == 0 &&
				String::Compare(rolActual, rolCBOX->Text, true) != 0) {
				MessageBox::Show("No se puede cambiar el rol de un Administrador");
				return;
			}
			std::string nombre = msclr::interop::marshal_as<std::string>(nomTBX->Text);
			std::string apellido = msclr::interop::marshal_as<std::string>(apeTBX->Text);
			std::string password = msclr::interop::marshal_as<std::string>(passTBX->Text);
			std::string rol = msclr::interop::marshal_as<std::string>(rolCBOX->Text);
			std::string numDoc = msclr::interop::marshal_as<std::string>(NumDoTBX->Text);
			std::string tipoDoc = msclr::interop::marshal_as<std::string>(tipoCBOX->Text);
			std::string correo = msclr::interop::marshal_as<std::string>(emailTBX->Text);
			std::string telefono = msclr::interop::marshal_as<std::string>(telefTBX->Text);
			std::string calle = msclr::interop::marshal_as<std::string>(calleTBX->Text);
			std::string numero = msclr::interop::marshal_as<std::string>(numCTBX->Text);
			std::string ciudad = msclr::interop::marshal_as<std::string>(ciudTBX->Text);

			modificarPersonaCompleta(idPersona, nombre, apellido, password, rol,
				numDoc, tipoDoc, correo, telefono, calle, numero, ciudad);
			cargarAdministradores(dataGridView1);
			MessageBox::Show("Persona modificada correctamente");
			nomTBX->Text = L"";
			apeTBX->Text = L"";
			passTBX->Text = L"";
			rolCBOX->SelectedIndex = 0;
			NumDoTBX->Text = L"";
			tipoCBOX->SelectedIndex = 0;
			emailTBX->Text = L"";
			telefTBX->Text = L"";
			calleTBX->Text = L"";
			numCTBX->Text = L"";
			ciudTBX->Text = L"";
			idpersonaTBX->Text = L"";
			dataGridView1->ClearSelection();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void numCTBX_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0) return;
		DataGridViewRow^ row = dataGridView1->Rows[e->RowIndex];
		idpersonaTBX->Text = row->Cells["ID"]->Value->ToString();
		nomTBX->Text = row->Cells["Nombre"]->Value->ToString();
		apeTBX->Text = row->Cells["Apellido"]->Value->ToString();
		passTBX->Text = row->Cells["Password"]->Value->ToString();
		rolCBOX->Text = row->Cells["Rol"]->Value->ToString();
		emailTBX->Text = row->Cells["Email"]->Value->ToString();
		telefTBX->Text = row->Cells["Telefono"]->Value->ToString();
		NumDoTBX->Text = row->Cells["NumDoc"]->Value->ToString();
		tipoCBOX->Text = row->Cells["TipoDoc"]->Value->ToString();
		calleTBX->Text = row->Cells["Calle"]->Value->ToString();
		numCTBX->Text = row->Cells["Numero"]->Value->ToString();
		ciudTBX->Text = row->Cells["Ciudad"]->Value->ToString();
	}

	};
}
