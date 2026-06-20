#pragma once
//#include "pelisVar.h"

#include <msclr/marshal_cppstd.h>
using namespace  std;
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
	public:
		CLIENTES(void)
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

	private: System::Windows::Forms::TextBox^ idTBX;
	private: System::Windows::Forms::TextBox^ nomTBX;
	private: System::Windows::Forms::TextBox^ apeTBX;
	private: System::Windows::Forms::TextBox^ telTBX;
	private: System::Windows::Forms::TextBox^ gmailTBX;










	private: System::Windows::Forms::DataGridView^ table1;
	private: System::Windows::Forms::Button^ emplBTN;
	private: System::Windows::Forms::TextBox^ passTBX;

	private: System::Windows::Forms::TextBox^ rolTBX;
	private: System::Windows::Forms::Label^ label7;



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
			this->idTBX = (gcnew System::Windows::Forms::TextBox());
			this->nomTBX = (gcnew System::Windows::Forms::TextBox());
			this->apeTBX = (gcnew System::Windows::Forms::TextBox());
			this->telTBX = (gcnew System::Windows::Forms::TextBox());
			this->gmailTBX = (gcnew System::Windows::Forms::TextBox());
			this->table1 = (gcnew System::Windows::Forms::DataGridView());
			this->emplBTN = (gcnew System::Windows::Forms::Button());
			this->passTBX = (gcnew System::Windows::Forms::TextBox());
			this->rolTBX = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
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
			this->label1->Location = System::Drawing::Point(36, 122);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"ID_PERSONA";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(36, 178);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"NOMBRE";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(36, 220);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"APELLIDO";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(36, 259);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"TELEFONO";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(307, 172);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"GMAIL";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(307, 218);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"PASSWORD";
			// 
			// idTBX
			// 
			this->idTBX->Location = System::Drawing::Point(39, 139);
			this->idTBX->Name = L"idTBX";
			this->idTBX->Size = System::Drawing::Size(253, 20);
			this->idTBX->TabIndex = 14;
			this->idTBX->TextChanged += gcnew System::EventHandler(this, &CLIENTES::idTBX_TextChanged);
			// 
			// nomTBX
			// 
			this->nomTBX->Location = System::Drawing::Point(39, 197);
			this->nomTBX->Name = L"nomTBX";
			this->nomTBX->Size = System::Drawing::Size(253, 20);
			this->nomTBX->TabIndex = 15;
			this->nomTBX->TextChanged += gcnew System::EventHandler(this, &CLIENTES::nomTBX_TextChanged);
			// 
			// apeTBX
			// 
			this->apeTBX->Location = System::Drawing::Point(39, 236);
			this->apeTBX->Name = L"apeTBX";
			this->apeTBX->Size = System::Drawing::Size(253, 20);
			this->apeTBX->TabIndex = 16;
			this->apeTBX->TextChanged += gcnew System::EventHandler(this, &CLIENTES::apeTBX_TextChanged);
			// 
			// telTBX
			// 
			this->telTBX->Location = System::Drawing::Point(39, 278);
			this->telTBX->Name = L"telTBX";
			this->telTBX->Size = System::Drawing::Size(253, 20);
			this->telTBX->TabIndex = 17;
			this->telTBX->TextChanged += gcnew System::EventHandler(this, &CLIENTES::telTBX_TextChanged);
			// 
			// gmailTBX
			// 
			this->gmailTBX->Location = System::Drawing::Point(310, 188);
			this->gmailTBX->Name = L"gmailTBX";
			this->gmailTBX->Size = System::Drawing::Size(253, 20);
			this->gmailTBX->TabIndex = 18;
			this->gmailTBX->TextChanged += gcnew System::EventHandler(this, &CLIENTES::gmailTBX_TextChanged);
			// 
			// table1
			// 
			this->table1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->table1->Location = System::Drawing::Point(12, 349);
			this->table1->Name = L"table1";
			this->table1->Size = System::Drawing::Size(762, 221);
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
			this->passTBX->Location = System::Drawing::Point(310, 234);
			this->passTBX->Name = L"passTBX";
			this->passTBX->Size = System::Drawing::Size(253, 20);
			this->passTBX->TabIndex = 19;
			this->passTBX->TextChanged += gcnew System::EventHandler(this, &CLIENTES::passTBX_TextChanged);
			// 
			// rolTBX
			// 
			this->rolTBX->Location = System::Drawing::Point(310, 277);
			this->rolTBX->Name = L"rolTBX";
			this->rolTBX->Size = System::Drawing::Size(253, 20);
			this->rolTBX->TabIndex = 24;
			this->rolTBX->TextChanged += gcnew System::EventHandler(this, &CLIENTES::rolTBX_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(307, 259);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(29, 13);
			this->label7->TabIndex = 25;
			this->label7->Text = L"ROL";
			// 
			// CLIENTES
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(786, 582);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->rolTBX);
			this->Controls->Add(this->emplBTN);
			this->Controls->Add(this->table1);
			this->Controls->Add(this->passTBX);
			this->Controls->Add(this->gmailTBX);
			this->Controls->Add(this->telTBX);
			this->Controls->Add(this->apeTBX);
			this->Controls->Add(this->nomTBX);
			this->Controls->Add(this->idTBX);
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
			this->Name = L"CLIENTES";
			this->Text = L"CLIENTES";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void facBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void stockBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void provBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void emplBTN_Click(System::Object^ sender, System::EventArgs^ e) {

	}


	private: System::Void ingrBTN_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void eliBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void modiBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}



	private: System::Void idTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
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

	};



}
