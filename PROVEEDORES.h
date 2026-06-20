//#include "pelisVar.h"

#include <msclr/marshal_cppstd.h>
using namespace  std;
/* para q andé  los cambios de vistas... en BTN
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
	public ref class PROVEEDORES : public System::Windows::Forms::Form
	{
	public:
		PROVEEDORES(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
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
	private: System::Windows::Forms::TextBox^ nomTBX;
	private: System::Windows::Forms::TextBox^ domiTBX;

	private: System::Windows::Forms::TextBox^ telTBX;
	private: System::Windows::Forms::TextBox^ gmailTBX;










	private: System::Windows::Forms::DataGridView^ table1;
	







	protected:

	protected:




	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
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
			this->nomTBX = (gcnew System::Windows::Forms::TextBox());
			this->domiTBX = (gcnew System::Windows::Forms::TextBox());
			this->telTBX = (gcnew System::Windows::Forms::TextBox());
			this->gmailTBX = (gcnew System::Windows::Forms::TextBox());
			this->table1 = (gcnew System::Windows::Forms::DataGridView());
			this->emplBTN = (gcnew System::Windows::Forms::Button());
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
			this->ingrBTN->Location = System::Drawing::Point(621, 165);
			this->ingrBTN->Name = L"ingrBTN";
			this->ingrBTN->Size = System::Drawing::Size(120, 29);
			this->ingrBTN->TabIndex = 4;
			this->ingrBTN->Text = L"INGRESAR";
			this->ingrBTN->UseVisualStyleBackColor = true;
			this->ingrBTN->Click += gcnew System::EventHandler(this, &PROVEEDORES::ingrBTN_Click);
			// 
			// eliBTN
			// 
			this->eliBTN->Location = System::Drawing::Point(621, 200);
			this->eliBTN->Name = L"eliBTN";
			this->eliBTN->Size = System::Drawing::Size(118, 25);
			this->eliBTN->TabIndex = 5;
			this->eliBTN->Text = L"ELIMINAR";
			this->eliBTN->UseVisualStyleBackColor = true;
			this->eliBTN->Click += gcnew System::EventHandler(this, &PROVEEDORES::eliBTN_Click);
			// 
			// modiBTN
			// 
			this->modiBTN->Location = System::Drawing::Point(621, 231);
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
			this->label1->Location = System::Drawing::Point(36, 122);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"ID_PROVEEDOR";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(36, 172);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"NOMBRE";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(307, 220);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"DOMICILIO";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(36, 220);
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
			// idTBX
			// 
			this->idTBX->Location = System::Drawing::Point(39, 139);
			this->idTBX->Name = L"idTBX";
			this->idTBX->Size = System::Drawing::Size(253, 20);
			this->idTBX->TabIndex = 14;
			this->idTBX->TextChanged += gcnew System::EventHandler(this, &PROVEEDORES::idTBX_TextChanged);
			// 
			// nomTBX
			// 
			this->nomTBX->Location = System::Drawing::Point(39, 188);
			this->nomTBX->Name = L"nomTBX";
			this->nomTBX->Size = System::Drawing::Size(253, 20);
			this->nomTBX->TabIndex = 15;
			this->nomTBX->TextChanged += gcnew System::EventHandler(this, &PROVEEDORES::nomTBX_TextChanged);
			// 
			// domiTBX
			// 
			this->domiTBX->Location = System::Drawing::Point(310, 236);
			this->domiTBX->Name = L"domiTBX";
			this->domiTBX->Size = System::Drawing::Size(253, 20);
			this->domiTBX->TabIndex = 16;
			// 
			// telTBX
			// 
			this->telTBX->Location = System::Drawing::Point(39, 236);
			this->telTBX->Name = L"telTBX";
			this->telTBX->Size = System::Drawing::Size(253, 20);
			this->telTBX->TabIndex = 17;
			this->telTBX->TextChanged += gcnew System::EventHandler(this, &PROVEEDORES::telTBX_TextChanged);
			// 
			// gmailTBX
			// 
			this->gmailTBX->Location = System::Drawing::Point(310, 188);
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
			// 
			// PROVEEDORES
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(786, 582);
			this->Controls->Add(this->emplBTN);
			this->Controls->Add(this->table1);
			this->Controls->Add(this->gmailTBX);
			this->Controls->Add(this->telTBX);
			this->Controls->Add(this->domiTBX);
			this->Controls->Add(this->nomTBX);
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
	private: System::Void stockBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void provBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void cliBTN_Click(System::Object^ sender, System::EventArgs^ e) {
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

	private: System::Void telTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void gmailTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}



};



}
