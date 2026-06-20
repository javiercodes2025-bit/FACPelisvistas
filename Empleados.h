#include "peliVAR.h"

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
	public ref class EMPLEADOS : public System::Windows::Forms::Form
	{
	public:
		EMPLEADOS(void)
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






	private: System::Windows::Forms::TextBox^ idTBX;






	private: System::Windows::Forms::DataGridView^ table1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ entrTBX;
	private: System::Windows::Forms::TextBox^ saliTBX;
	private: System::Windows::Forms::TextBox^ sueldoTBX;



	private: System::Windows::Forms::Label^ label4;


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
			this->facBTN->Click += gcnew System::EventHandler(this, &EMPLEADOS::facBTN_Click);
			// 
			// cliBTN
			// 
			this->cliBTN->Location = System::Drawing::Point(213, 28);
			this->cliBTN->Name = L"cliBTN";
			this->cliBTN->Size = System::Drawing::Size(172, 26);
			this->cliBTN->TabIndex = 1;
			this->cliBTN->Text = L"CLIENTES";
			this->cliBTN->UseVisualStyleBackColor = true;
			this->cliBTN->Click += gcnew System::EventHandler(this, &EMPLEADOS::cliBTN_Click);
			// 
			// provBTN
			// 
			this->provBTN->Location = System::Drawing::Point(391, 29);
			this->provBTN->Name = L"provBTN";
			this->provBTN->Size = System::Drawing::Size(172, 25);
			this->provBTN->TabIndex = 2;
			this->provBTN->Text = L"PROVEEDORES";
			this->provBTN->UseVisualStyleBackColor = true;
			this->provBTN->Click += gcnew System::EventHandler(this, &EMPLEADOS::provBTN_Click);
			// 
			// stockBTN
			// 
			this->stockBTN->Location = System::Drawing::Point(569, 28);
			this->stockBTN->Name = L"stockBTN";
			this->stockBTN->Size = System::Drawing::Size(168, 26);
			this->stockBTN->TabIndex = 3;
			this->stockBTN->Text = L"STOCK";
			this->stockBTN->UseVisualStyleBackColor = true;
			this->stockBTN->Click += gcnew System::EventHandler(this, &EMPLEADOS::stockBTN_Click);
			// 
			// ingrBTN
			// 
			this->ingrBTN->Location = System::Drawing::Point(627, 196);
			this->ingrBTN->Name = L"ingrBTN";
			this->ingrBTN->Size = System::Drawing::Size(120, 29);
			this->ingrBTN->TabIndex = 4;
			this->ingrBTN->Text = L"INGRESAR";
			this->ingrBTN->UseVisualStyleBackColor = true;
			this->ingrBTN->Click += gcnew System::EventHandler(this, &EMPLEADOS::ingrBTN_Click);
			// 
			// eliBTN
			// 
			this->eliBTN->Location = System::Drawing::Point(627, 231);
			this->eliBTN->Name = L"eliBTN";
			this->eliBTN->Size = System::Drawing::Size(118, 25);
			this->eliBTN->TabIndex = 5;
			this->eliBTN->Text = L"ELIMINAR";
			this->eliBTN->UseVisualStyleBackColor = true;
			this->eliBTN->Click += gcnew System::EventHandler(this, &EMPLEADOS::eliBTN_Click);
			// 
			// modiBTN
			// 
			this->modiBTN->Location = System::Drawing::Point(627, 262);
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
			this->label1->Location = System::Drawing::Point(36, 103);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"ID_PERSONA";
			// 
			// idTBX
			// 
			this->idTBX->Location = System::Drawing::Point(39, 120);
			this->idTBX->Name = L"idTBX";
			this->idTBX->Size = System::Drawing::Size(253, 20);
			this->idTBX->TabIndex = 14;
			this->idTBX->TextChanged += gcnew System::EventHandler(this, &EMPLEADOS::idTBX_TextChanged);
			// 
			// table1
			// 
			this->table1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->table1->Location = System::Drawing::Point(12, 293);
			this->table1->Name = L"table1";
			this->table1->Size = System::Drawing::Size(762, 277);
			this->table1->TabIndex = 21;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(39, 171);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 22;
			this->label2->Text = L"Hora_Entrada";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(39, 211);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 13);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Hora_Salida";
			// 
			// entrTBX
			// 
			this->entrTBX->Location = System::Drawing::Point(42, 188);
			this->entrTBX->Name = L"entrTBX";
			this->entrTBX->Size = System::Drawing::Size(250, 20);
			this->entrTBX->TabIndex = 24;
			this->entrTBX->TextChanged += gcnew System::EventHandler(this, &EMPLEADOS::entrTBX_TextChanged);
			// 
			// saliTBX
			// 
			this->saliTBX->Location = System::Drawing::Point(42, 227);
			this->saliTBX->Name = L"saliTBX";
			this->saliTBX->Size = System::Drawing::Size(250, 20);
			this->saliTBX->TabIndex = 25;
			this->saliTBX->TextChanged += gcnew System::EventHandler(this, &EMPLEADOS::saliTBX_TextChanged);
			// 
			// sueldoTBX
			// 
			this->sueldoTBX->Location = System::Drawing::Point(321, 188);
			this->sueldoTBX->Name = L"sueldoTBX";
			this->sueldoTBX->Size = System::Drawing::Size(242, 20);
			this->sueldoTBX->TabIndex = 26;
			this->sueldoTBX->TextChanged += gcnew System::EventHandler(this, &EMPLEADOS::sueldoTBX_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(321, 170);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 13);
			this->label4->TabIndex = 27;
			this->label4->Text = L"Sueldo";
			// 
			// EMPLEADOS
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(786, 582);
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

	private: System::Void cliBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void provBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void stockBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}



	private: System::Void ingrBTN_Click(System::Object^ sender, System::EventArgs^ e) {


	}
	private: System::Void eliBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void modiBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}



	private: System::Void idTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	
	private: System::Void entrTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void saliTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void sueldoTBX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

};



}
