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
	public ref class STOCK : public System::Windows::Forms::Form
	{
	public:
		STOCK(void)
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
		~STOCK()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ facBTN;
	private: System::Windows::Forms::Button^ cliBTN;
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
	private: System::Windows::Forms::TextBox^ tituTBX;
	private: System::Windows::Forms::TextBox^ anioTBX;
	private: System::Windows::Forms::TextBox^ duraTBX;
	private: System::Windows::Forms::TextBox^ precTBX;






	private: System::Windows::Forms::DataGridView^ table1;
	private: System::Windows::Forms::Button^ emplBTN;
	private: System::Windows::Forms::TextBox^ canTBX;



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
			this->tituTBX = (gcnew System::Windows::Forms::TextBox());
			this->anioTBX = (gcnew System::Windows::Forms::TextBox());
			this->duraTBX = (gcnew System::Windows::Forms::TextBox());
			this->precTBX = (gcnew System::Windows::Forms::TextBox());
			this->table1 = (gcnew System::Windows::Forms::DataGridView());
			this->emplBTN = (gcnew System::Windows::Forms::Button());
			this->canTBX = (gcnew System::Windows::Forms::TextBox());
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
			this->facBTN->Click += gcnew System::EventHandler(this, &STOCK::facBTN_Click);
			// 
			// cliBTN
			// 
			this->cliBTN->Location = System::Drawing::Point(213, 28);
			this->cliBTN->Name = L"cliBTN";
			this->cliBTN->Size = System::Drawing::Size(172, 26);
			this->cliBTN->TabIndex = 1;
			this->cliBTN->Text = L"CLIENTES";
			this->cliBTN->UseVisualStyleBackColor = true;
			this->cliBTN->Click += gcnew System::EventHandler(this, &STOCK::cliBTN_Click);
			// 
			// provBTN
			// 
			this->provBTN->Location = System::Drawing::Point(391, 29);
			this->provBTN->Name = L"provBTN";
			this->provBTN->Size = System::Drawing::Size(172, 25);
			this->provBTN->TabIndex = 2;
			this->provBTN->Text = L"PROVEEDORES";
			this->provBTN->UseVisualStyleBackColor = true;
			this->provBTN->Click += gcnew System::EventHandler(this, &STOCK::provBTN_Click);
			// 
			// ingrBTN
			// 
			this->ingrBTN->Location = System::Drawing::Point(627, 196);
			this->ingrBTN->Name = L"ingrBTN";
			this->ingrBTN->Size = System::Drawing::Size(120, 29);
			this->ingrBTN->TabIndex = 4;
			this->ingrBTN->Text = L"INGRESAR";
			this->ingrBTN->UseVisualStyleBackColor = true;
			this->ingrBTN->Click += gcnew System::EventHandler(this, &STOCK::ingrBTN_Click);
			// 
			// eliBTN
			// 
			this->eliBTN->Location = System::Drawing::Point(627, 231);
			this->eliBTN->Name = L"eliBTN";
			this->eliBTN->Size = System::Drawing::Size(118, 25);
			this->eliBTN->TabIndex = 5;
			this->eliBTN->Text = L"ELIMINAR";
			this->eliBTN->UseVisualStyleBackColor = true;
			this->eliBTN->Click += gcnew System::EventHandler(this, &STOCK::eliBTN_Click);
			// 
			// modiBTN
			// 
			this->modiBTN->Location = System::Drawing::Point(627, 262);
			this->modiBTN->Name = L"modiBTN";
			this->modiBTN->Size = System::Drawing::Size(120, 25);
			this->modiBTN->TabIndex = 6;
			this->modiBTN->Text = L"MODIFICAR";
			this->modiBTN->UseVisualStyleBackColor = true;
			this->modiBTN->Click += gcnew System::EventHandler(this, &STOCK::modiBTN_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(36, 122);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"ID_PELICULA";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(36, 178);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"TITULO";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(36, 220);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(30, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"A�O";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(36, 259);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"DURACION";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(307, 181);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(47, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"PRECIO";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(307, 227);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(62, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"CANTIDAD";
			// 
			// idTBX
			// 
			this->idTBX->Location = System::Drawing::Point(39, 139);
			this->idTBX->Name = L"idTBX";
			this->idTBX->Size = System::Drawing::Size(253, 20);
			this->idTBX->TabIndex = 14;
			this->idTBX->TextChanged += gcnew System::EventHandler(this, &STOCK::idTBX_TextChanged);
			// 
			// tituTBX
			// 
			this->tituTBX->Location = System::Drawing::Point(39, 197);
			this->tituTBX->Name = L"tituTBX";
			this->tituTBX->Size = System::Drawing::Size(253, 20);
			this->tituTBX->TabIndex = 15;
			this->tituTBX->TextChanged += gcnew System::EventHandler(this, &STOCK::tituTBX_TextChanged);
			// 
			// anioTBX
			// 
			this->anioTBX->Location = System::Drawing::Point(39, 236);
			this->anioTBX->Name = L"anioTBX";
			this->anioTBX->Size = System::Drawing::Size(253, 20);
			this->anioTBX->TabIndex = 16;
			this->anioTBX->TextChanged += gcnew System::EventHandler(this, &STOCK::anioTBX_TextChanged);
			// 
			// duraTBX
			// 
			this->duraTBX->Location = System::Drawing::Point(39, 278);
			this->duraTBX->Name = L"duraTBX";
			this->duraTBX->Size = System::Drawing::Size(253, 20);
			this->duraTBX->TabIndex = 17;
			this->duraTBX->TextChanged += gcnew System::EventHandler(this, &STOCK::duraTBX_TextChanged);
			// 
			// precTBX
			// 
			this->precTBX->Location = System::Drawing::Point(310, 197);
			this->precTBX->Name = L"precTBX";
			this->precTBX->Size = System::Drawing::Size(253, 20);
			this->precTBX->TabIndex = 18;
			this->precTBX->TextChanged += gcnew System::EventHandler(this, &STOCK::precTBX_TextChanged);
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
			this->emplBTN->Location = System::Drawing::Point(584, 28);
			this->emplBTN->Name = L"emplBTN";
			this->emplBTN->Size = System::Drawing::Size(163, 24);
			this->emplBTN->TabIndex = 23;
			this->emplBTN->Text = L"EMPLEADOS";
			this->emplBTN->UseVisualStyleBackColor = true;
			this->emplBTN->Click += gcnew System::EventHandler(this, &STOCK::emplBTN_Click);
			// 
			// canTBX
			// 
			this->canTBX->Location = System::Drawing::Point(310, 243);
			this->canTBX->Name = L"canTBX";
			this->canTBX->Size = System::Drawing::Size(253, 20);
			this->canTBX->TabIndex = 19;
			this->canTBX->TextChanged += gcnew System::EventHandler(this, &STOCK::canTBX_TextChanged);
			// 
			// STOCK
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(786, 582);
			this->Controls->Add(this->emplBTN);
			this->Controls->Add(this->table1);
			this->Controls->Add(this->canTBX);
			this->Controls->Add(this->precTBX);
			this->Controls->Add(this->duraTBX);
			this->Controls->Add(this->anioTBX);
			this->Controls->Add(this->tituTBX);
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
			this->Controls->Add(this->cliBTN);
			this->Controls->Add(this->facBTN);
			this->Name = L"STOCK";
			this->Text = L"STOCK";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void facBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void cliBTN_Click(System::Object^ sender, System::EventArgs^ e) {
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
	private: System::Void tituTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void anioTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void duraTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void precTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void canTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}


	};



}
