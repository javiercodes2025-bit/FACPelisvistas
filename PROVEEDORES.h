#pragma once
//#include "pelisVar.h"

#include <msclr/marshal_cppstd.h>
using namespace  std;
/* para q and�  los cambios de vistas... en BTN
#include <".h">
#include <".h">
#include <".h">
#include <".h"> */

ref class CLIENTES;
ref class EMPLEADOS;
ref class STOCK;


namespace FACPelisVistas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class PROVEEDORES : public System::Windows::Forms::Form
	{
	public:
		PROVEEDORES(void)
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
		~PROVEEDORES()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ facBTN;
	private: System::Windows::Forms::Button^ stockBTN;
	private: System::Windows::Forms::Button^ cliBTN;
	private: System::Windows::Forms::Button^ emplBTN;


	private: System::Windows::Forms::Button^ ingrBTN;


	private: System::Windows::Forms::Button^ eliBTN;

	private: System::Windows::Forms::Button^ modiBTN;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;


	private: System::Windows::Forms::TextBox^ idTBX;
	private: System::Windows::Forms::TextBox^ nombreTBX;

	private: System::Windows::Forms::TextBox^ domicilioTBX;
	private: System::Windows::Forms::TextBox^ telefonoTBX;



	private: System::Windows::Forms::TextBox^ gmailTBX;










	private: System::Windows::Forms::DataGridView^ table1;
	private: System::Windows::Forms::Label^ CodigoBarra;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ NOMBRE;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ codigobarraTXB;
	private: System::Windows::Forms::TextBox^ pelinombreTXB;
	private: System::Windows::Forms::TextBox^ peliANIOTBX;
	private: System::Windows::Forms::TextBox^ peliduracionTBX;
	private: System::Windows::Forms::Button^ buscadorTBX;











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
			this->cliBTN = (gcnew System::Windows::Forms::Button());
			this->ingrBTN = (gcnew System::Windows::Forms::Button());
			this->eliBTN = (gcnew System::Windows::Forms::Button());
			this->modiBTN = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->idTBX = (gcnew System::Windows::Forms::TextBox());
			this->nombreTBX = (gcnew System::Windows::Forms::TextBox());
			this->domicilioTBX = (gcnew System::Windows::Forms::TextBox());
			this->telefonoTBX = (gcnew System::Windows::Forms::TextBox());
			this->gmailTBX = (gcnew System::Windows::Forms::TextBox());
			this->table1 = (gcnew System::Windows::Forms::DataGridView());
			this->emplBTN = (gcnew System::Windows::Forms::Button());
			this->CodigoBarra = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->NOMBRE = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->codigobarraTXB = (gcnew System::Windows::Forms::TextBox());
			this->pelinombreTXB = (gcnew System::Windows::Forms::TextBox());
			this->peliANIOTBX = (gcnew System::Windows::Forms::TextBox());
			this->peliduracionTBX = (gcnew System::Windows::Forms::TextBox());
			this->buscadorTBX = (gcnew System::Windows::Forms::Button());
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
			this->facBTN->Click += gcnew System::EventHandler(this, &PROVEEDORES::facBTN_Click);
			// 
			// stockBTN
			// 
			this->stockBTN->Location = System::Drawing::Point(569, 27);
			this->stockBTN->Name = L"stockBTN";
			this->stockBTN->Size = System::Drawing::Size(172, 26);
			this->stockBTN->TabIndex = 1;
			this->stockBTN->Text = L"STOCK";
			this->stockBTN->UseVisualStyleBackColor = true;
			this->stockBTN->Click += gcnew System::EventHandler(this, &PROVEEDORES::stockBTN_Click);
			// 
			// cliBTN
			// 
			this->cliBTN->Location = System::Drawing::Point(382, 28);
			this->cliBTN->Name = L"cliBTN";
			this->cliBTN->Size = System::Drawing::Size(181, 25);
			this->cliBTN->TabIndex = 2;
			this->cliBTN->Text = L"CLIENTES";
			this->cliBTN->UseVisualStyleBackColor = true;
			this->cliBTN->Click += gcnew System::EventHandler(this, &PROVEEDORES::cliBTN_Click);
			// 
			// ingrBTN
			// 
			this->ingrBTN->Location = System::Drawing::Point(621, 216);
			this->ingrBTN->Name = L"ingrBTN";
			this->ingrBTN->Size = System::Drawing::Size(120, 29);
			this->ingrBTN->TabIndex = 4;
			this->ingrBTN->Text = L"INGRESAR";
			this->ingrBTN->UseVisualStyleBackColor = true;
			this->ingrBTN->Click += gcnew System::EventHandler(this, &PROVEEDORES::ingrBTN_Click);
			// 
			// eliBTN
			// 
			this->eliBTN->Location = System::Drawing::Point(621, 251);
			this->eliBTN->Name = L"eliBTN";
			this->eliBTN->Size = System::Drawing::Size(118, 25);
			this->eliBTN->TabIndex = 5;
			this->eliBTN->Text = L"ELIMINAR";
			this->eliBTN->UseVisualStyleBackColor = true;
			this->eliBTN->Click += gcnew System::EventHandler(this, &PROVEEDORES::eliBTN_Click);
			// 
			// modiBTN
			// 
			this->modiBTN->Location = System::Drawing::Point(621, 282);
			this->modiBTN->Name = L"modiBTN";
			this->modiBTN->Size = System::Drawing::Size(120, 25);
			this->modiBTN->TabIndex = 6;
			this->modiBTN->Text = L"MODIFICAR";
			this->modiBTN->UseVisualStyleBackColor = true;
			this->modiBTN->Click += gcnew System::EventHandler(this, &PROVEEDORES::modiBTN_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(36, 173);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"ID_PROVEEDOR";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(36, 223);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"NOMBRE";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(307, 271);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"DOMICILIO";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(36, 271);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"TELEFONO";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(307, 223);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"GMAIL";
			// 
			// idTBX
			// 
			this->idTBX->Location = System::Drawing::Point(39, 190);
			this->idTBX->Name = L"idTBX";
			this->idTBX->Size = System::Drawing::Size(253, 20);
			this->idTBX->TabIndex = 14;
			this->idTBX->TextChanged += gcnew System::EventHandler(this, &PROVEEDORES::idTBX_TextChanged);
			// 
			// nombreTBX
			// 
			this->nombreTBX->Location = System::Drawing::Point(39, 239);
			this->nombreTBX->Name = L"nombreTBX";
			this->nombreTBX->Size = System::Drawing::Size(253, 20);
			this->nombreTBX->TabIndex = 15;
			this->nombreTBX->TextChanged += gcnew System::EventHandler(this, &PROVEEDORES::nomTBX_TextChanged);
			// 
			// domicilioTBX
			// 
			this->domicilioTBX->Location = System::Drawing::Point(310, 287);
			this->domicilioTBX->Name = L"domicilioTBX";
			this->domicilioTBX->Size = System::Drawing::Size(253, 20);
			this->domicilioTBX->TabIndex = 16;
			// 
			// telefonoTBX
			// 
			this->telefonoTBX->Location = System::Drawing::Point(39, 287);
			this->telefonoTBX->Name = L"telefonoTBX";
			this->telefonoTBX->Size = System::Drawing::Size(253, 20);
			this->telefonoTBX->TabIndex = 17;
			this->telefonoTBX->TextChanged += gcnew System::EventHandler(this, &PROVEEDORES::telTBX_TextChanged);
			// 
			// gmailTBX
			// 
			this->gmailTBX->Location = System::Drawing::Point(310, 239);
			this->gmailTBX->Name = L"gmailTBX";
			this->gmailTBX->Size = System::Drawing::Size(253, 20);
			this->gmailTBX->TabIndex = 18;
			this->gmailTBX->TextChanged += gcnew System::EventHandler(this, &PROVEEDORES::gmailTBX_TextChanged);
			// 
			// table1
			// 
			this->table1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->table1->Location = System::Drawing::Point(12, 329);
			this->table1->Name = L"table1";
			this->table1->Size = System::Drawing::Size(762, 241);
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
			this->emplBTN->Click += gcnew System::EventHandler(this, &PROVEEDORES::emplBTN_Click);
			// 
			// CodigoBarra
			// 
			this->CodigoBarra->AutoSize = true;
			this->CodigoBarra->Location = System::Drawing::Point(36, 71);
			this->CodigoBarra->Name = L"CodigoBarra";
			this->CodigoBarra->Size = System::Drawing::Size(65, 13);
			this->CodigoBarra->TabIndex = 24;
			this->CodigoBarra->Text = L"CodigoBarra";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(446, 116);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(64, 13);
			this->label7->TabIndex = 25;
			this->label7->Text = L"DURACION";
			// 
			// NOMBRE
			// 
			this->NOMBRE->AutoSize = true;
			this->NOMBRE->Location = System::Drawing::Point(36, 116);
			this->NOMBRE->Name = L"NOMBRE";
			this->NOMBRE->Size = System::Drawing::Size(54, 13);
			this->NOMBRE->TabIndex = 26;
			this->NOMBRE->Text = L"NOMBRE";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(300, 116);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(33, 13);
			this->label9->TabIndex = 27;
			this->label9->Text = L"ANIO";
			// 
			// codigobarraTXB
			// 
			this->codigobarraTXB->Location = System::Drawing::Point(39, 87);
			this->codigobarraTXB->Name = L"codigobarraTXB";
			this->codigobarraTXB->Size = System::Drawing::Size(253, 20);
			this->codigobarraTXB->TabIndex = 28;
			// 
			// pelinombreTXB
			// 
			this->pelinombreTXB->Location = System::Drawing::Point(39, 133);
			this->pelinombreTXB->Name = L"pelinombreTXB";
			this->pelinombreTXB->Size = System::Drawing::Size(253, 20);
			this->pelinombreTXB->TabIndex = 29;
			this->pelinombreTXB->ReadOnly = true;
			// 
			// peliANIOTBX
			// 
			this->peliANIOTBX->Location = System::Drawing::Point(303, 132);
			this->peliANIOTBX->Name = L"peliANIOTBX";
			this->peliANIOTBX->Size = System::Drawing::Size(135, 20);
			this->peliANIOTBX->TabIndex = 30;
			this->peliANIOTBX->ReadOnly = true;
			// 
			// peliduracionTBX
			// 
			this->peliduracionTBX->Location = System::Drawing::Point(449, 132);
			this->peliduracionTBX->Name = L"peliduracionTBX";
			this->peliduracionTBX->Size = System::Drawing::Size(114, 20);
			this->peliduracionTBX->TabIndex = 31;
			this->peliduracionTBX->ReadOnly = true;
			// 
			// buscadorTBX
			// 
			this->buscadorTBX->Location = System::Drawing::Point(621, 129);
			this->buscadorTBX->Name = L"buscadorTBX";
			this->buscadorTBX->Size = System::Drawing::Size(126, 23);
			this->buscadorTBX->TabIndex = 32;
			this->buscadorTBX->Text = L"BUSCAR";
			this->buscadorTBX->UseVisualStyleBackColor = true;
			this->buscadorTBX->Click += gcnew System::EventHandler(this, &PROVEEDORES::buscadorTBX_Click);
			// 
			// PROVEEDORES
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(786, 582);
			this->Controls->Add(this->buscadorTBX);
			this->Controls->Add(this->peliduracionTBX);
			this->Controls->Add(this->peliANIOTBX);
			this->Controls->Add(this->pelinombreTXB);
			this->Controls->Add(this->codigobarraTXB);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->NOMBRE);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->CodigoBarra);
			this->Controls->Add(this->emplBTN);
			this->Controls->Add(this->table1);
			this->Controls->Add(this->gmailTBX);
			this->Controls->Add(this->telefonoTBX);
			this->Controls->Add(this->domicilioTBX);
			this->Controls->Add(this->nombreTBX);
			this->Controls->Add(this->idTBX);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->modiBTN);
			this->Controls->Add(this->eliBTN);
			this->Controls->Add(this->ingrBTN);
			this->Controls->Add(this->cliBTN);
			this->Controls->Add(this->stockBTN);
			this->Controls->Add(this->facBTN);
			this->Name = L"PROVEEDORES";
			this->Text = L"PROVEEDORES";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void facBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void stockBTN_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cliBTN_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void emplBTN_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void provBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buscadorTBX_Click(System::Object^ sender, System::EventArgs^ e);



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

	private: System::Void telTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void gmailTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}



};



}
