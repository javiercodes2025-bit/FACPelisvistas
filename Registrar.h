#pragma once
#include "peliVAR.h"

ref class Login;

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
	private: System::Windows::Forms::TextBox^ rolTBX;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ NumDoTBX;
	private: System::Windows::Forms::TextBox^ TiDocTBX;



	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ calleTBX;
	private: System::Windows::Forms::TextBox^ numCTBX;



	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ ciudTBX;
	private: System::Windows::Forms::TextBox^ proTBX;


	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
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
			this->rolTBX = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->NumDoTBX = (gcnew System::Windows::Forms::TextBox());
			this->TiDocTBX = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->calleTBX = (gcnew System::Windows::Forms::TextBox());
			this->numCTBX = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->ciudTBX = (gcnew System::Windows::Forms::TextBox());
			this->proTBX = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// regBTN
			// 
			this->regBTN->Location = System::Drawing::Point(101, 414);
			this->regBTN->Name = L"regBTN";
			this->regBTN->Size = System::Drawing::Size(350, 23);
			this->regBTN->TabIndex = 0;
			this->regBTN->Text = L"Registrar";
			this->regBTN->UseVisualStyleBackColor = true;
			this->regBTN->Click += gcnew System::EventHandler(this, &Registrar::regBTN_Click);
			// 
			// atrBTN
			// 
			this->atrBTN->Location = System::Drawing::Point(457, 414);
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
			this->label1->Location = System::Drawing::Point(31, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Nombre";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(31, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Apellido";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 297);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Telefono";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(31, 256);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(32, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Email";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(31, 128);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Password";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(31, 166);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(23, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Rol";
			// 
			// nomTBX
			// 
			this->nomTBX->Location = System::Drawing::Point(28, 61);
			this->nomTBX->Name = L"nomTBX";
			this->nomTBX->Size = System::Drawing::Size(315, 20);
			this->nomTBX->TabIndex = 8;
			// 
			// apeTBX
			// 
			this->apeTBX->Location = System::Drawing::Point(28, 100);
			this->apeTBX->Name = L"apeTBX";
			this->apeTBX->Size = System::Drawing::Size(315, 20);
			this->apeTBX->TabIndex = 9;
			// 
			// telefTBX
			// 
			this->telefTBX->Location = System::Drawing::Point(28, 313);
			this->telefTBX->Name = L"telefTBX";
			this->telefTBX->Size = System::Drawing::Size(315, 20);
			this->telefTBX->TabIndex = 10;
			// 
			// emailTBX
			// 
			this->emailTBX->Location = System::Drawing::Point(28, 271);
			this->emailTBX->Name = L"emailTBX";
			this->emailTBX->Size = System::Drawing::Size(315, 20);
			this->emailTBX->TabIndex = 11;
			// 
			// passTBX
			// 
			this->passTBX->Location = System::Drawing::Point(28, 144);
			this->passTBX->Name = L"passTBX";
			this->passTBX->Size = System::Drawing::Size(315, 20);
			this->passTBX->TabIndex = 12;
			// 
			// rolTBX
			// 
			this->rolTBX->Location = System::Drawing::Point(28, 182);
			this->rolTBX->Name = L"rolTBX";
			this->rolTBX->Size = System::Drawing::Size(315, 20);
			this->rolTBX->TabIndex = 13;
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
			this->NumDoTBX->Location = System::Drawing::Point(383, 61);
			this->NumDoTBX->Name = L"NumDoTBX";
			this->NumDoTBX->Size = System::Drawing::Size(315, 20);
			this->NumDoTBX->TabIndex = 15;
			// 
			// TiDocTBX
			// 
			this->TiDocTBX->Location = System::Drawing::Point(383, 101);
			this->TiDocTBX->Name = L"TiDocTBX";
			this->TiDocTBX->Size = System::Drawing::Size(315, 20);
			this->TiDocTBX->TabIndex = 16;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(380, 45);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(99, 13);
			this->label8->TabIndex = 17;
			this->label8->Text = L"NumeroDocumento";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(380, 85);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(83, 13);
			this->label9->TabIndex = 18;
			this->label9->Text = L"TipoDocumento";
			// 
			// calleTBX
			// 
			this->calleTBX->Location = System::Drawing::Point(383, 183);
			this->calleTBX->Name = L"calleTBX";
			this->calleTBX->Size = System::Drawing::Size(315, 20);
			this->calleTBX->TabIndex = 22;
			// 
			// numCTBX
			// 
			this->numCTBX->Location = System::Drawing::Point(383, 225);
			this->numCTBX->Name = L"numCTBX";
			this->numCTBX->Size = System::Drawing::Size(315, 20);
			this->numCTBX->TabIndex = 21;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(380, 167);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(30, 13);
			this->label10->TabIndex = 20;
			this->label10->Text = L"Calle";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(380, 209);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(44, 13);
			this->label11->TabIndex = 19;
			this->label11->Text = L"Numero";
			// 
			// ciudTBX
			// 
			this->ciudTBX->Location = System::Drawing::Point(383, 271);
			this->ciudTBX->Name = L"ciudTBX";
			this->ciudTBX->Size = System::Drawing::Size(315, 20);
			this->ciudTBX->TabIndex = 26;
			// 
			// proTBX
			// 
			this->proTBX->Location = System::Drawing::Point(383, 313);
			this->proTBX->Name = L"proTBX";
			this->proTBX->Size = System::Drawing::Size(315, 20);
			this->proTBX->TabIndex = 25;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(380, 255);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(40, 13);
			this->label12->TabIndex = 24;
			this->label12->Text = L"Ciudad";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(380, 297);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(51, 13);
			this->label13->TabIndex = 23;
			this->label13->Text = L"Provincia";
			// 
			// Registrar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(767, 478);
			this->Controls->Add(this->ciudTBX);
			this->Controls->Add(this->proTBX);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->calleTBX);
			this->Controls->Add(this->numCTBX);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->TiDocTBX);
			this->Controls->Add(this->NumDoTBX);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->rolTBX);
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
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void regBTN_Click(System::Object^ sender, System::EventArgs^ e) {

		try {

			std::string nombre =
				msclr::interop::marshal_as<std::string>(nomTBX->Text);

			std::string apellido =
				msclr::interop::marshal_as<std::string>(apeTBX->Text);

			std::string password =
				msclr::interop::marshal_as<std::string>(passTBX->Text);

			std::string rol =
				msclr::interop::marshal_as<std::string>(rolTBX->Text);

			std::string numeroDocumento =
				msclr::interop::marshal_as<std::string>(NumDoTBX->Text);

			std::string tipoDocumento =
				msclr::interop::marshal_as<std::string>(TiDocTBX->Text);

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

			std::string provincia =
				msclr::interop::marshal_as<std::string>(proTBX->Text);

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
				ciudad,
				provincia
			);

			con->conectVoid();
			con->insertarPersona();

			delete con;

			MessageBox::Show("Persona registrada");

		}
		catch (Exception^ ex) {

			MessageBox::Show(ex->Message);

		}
	}
	private: System::Void atrBTN_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
