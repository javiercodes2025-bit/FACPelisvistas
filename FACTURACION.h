#pragma once

namespace FACPelisvistas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FACTURACION
	/// </summary>
	public ref class FACTURACION : public System::Windows::Forms::Form
	{
	public:
		FACTURACION(void)
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
		~FACTURACION()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ clienteBTN;
	private: System::Windows::Forms::Button^ empleadosBTN;
	private: System::Windows::Forms::Button^ proveedoresBTN;
	private: System::Windows::Forms::Button^ stockBTN;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ buscadorClienteBTX;
	private: System::Windows::Forms::Button^ buscadorClienteBTN;

	private: System::Windows::Forms::Label^ NOM;
	private: System::Windows::Forms::TextBox^ nombreClienteBTX;

	private: System::Windows::Forms::DataGridView^ dataGridView1;



	protected:

	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->clienteBTN = (gcnew System::Windows::Forms::Button());
			this->empleadosBTN = (gcnew System::Windows::Forms::Button());
			this->proveedoresBTN = (gcnew System::Windows::Forms::Button());
			this->stockBTN = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buscadorClienteBTX = (gcnew System::Windows::Forms::TextBox());
			this->buscadorClienteBTN = (gcnew System::Windows::Forms::Button());
			this->NOM = (gcnew System::Windows::Forms::Label());
			this->nombreClienteBTX = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// clienteBTN
			// 
			this->clienteBTN->Location = System::Drawing::Point(26, 12);
			this->clienteBTN->Name = L"clienteBTN";
			this->clienteBTN->Size = System::Drawing::Size(184, 23);
			this->clienteBTN->TabIndex = 0;
			this->clienteBTN->Text = L"CLIENTES";
			this->clienteBTN->UseVisualStyleBackColor = true;
			this->clienteBTN->Click += gcnew System::EventHandler(this, &FACTURACION::clienteBTN_Click);
			// 
			// empleadosBTN
			// 
			this->empleadosBTN->Location = System::Drawing::Point(227, 12);
			this->empleadosBTN->Name = L"empleadosBTN";
			this->empleadosBTN->Size = System::Drawing::Size(201, 23);
			this->empleadosBTN->TabIndex = 1;
			this->empleadosBTN->Text = L"EMPLEADOS";
			this->empleadosBTN->UseVisualStyleBackColor = true;
			this->empleadosBTN->Click += gcnew System::EventHandler(this, &FACTURACION::empleadosBTN_Click);
			// 
			// proveedoresBTN
			// 
			this->proveedoresBTN->Location = System::Drawing::Point(444, 12);
			this->proveedoresBTN->Name = L"proveedoresBTN";
			this->proveedoresBTN->Size = System::Drawing::Size(201, 23);
			this->proveedoresBTN->TabIndex = 2;
			this->proveedoresBTN->Text = L"PROVEEDORES";
			this->proveedoresBTN->UseVisualStyleBackColor = true;
			this->proveedoresBTN->Click += gcnew System::EventHandler(this, &FACTURACION::proveedoresBTN_Click);
			// 
			// stockBTN
			// 
			this->stockBTN->Location = System::Drawing::Point(651, 12);
			this->stockBTN->Name = L"stockBTN";
			this->stockBTN->Size = System::Drawing::Size(184, 23);
			this->stockBTN->TabIndex = 3;
			this->stockBTN->Text = L"STOCK";
			this->stockBTN->UseVisualStyleBackColor = true;
			this->stockBTN->Click += gcnew System::EventHandler(this, &FACTURACION::stockBTN_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 73);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"C.DOCUMENTO";
			// 
			// buscadorClienteBTX
			// 
			this->buscadorClienteBTX->Location = System::Drawing::Point(29, 101);
			this->buscadorClienteBTX->Name = L"buscadorClienteBTX";
			this->buscadorClienteBTX->Size = System::Drawing::Size(181, 20);
			this->buscadorClienteBTX->TabIndex = 5;
			// 
			// buscadorClienteBTN
			// 
			this->buscadorClienteBTN->Location = System::Drawing::Point(359, 99);
			this->buscadorClienteBTN->Name = L"buscadorClienteBTN";
			this->buscadorClienteBTN->Size = System::Drawing::Size(99, 23);
			this->buscadorClienteBTN->TabIndex = 6;
			this->buscadorClienteBTN->Text = L"BuscadorCliente";
			this->buscadorClienteBTN->UseVisualStyleBackColor = true;
			this->buscadorClienteBTN->Click += gcnew System::EventHandler(this, &FACTURACION::buscadorClienteBTN_Click);
			// 
			// NOM
			// 
			this->NOM->AutoSize = true;
			this->NOM->Location = System::Drawing::Point(224, 85);
			this->NOM->Name = L"NOM";
			this->NOM->Size = System::Drawing::Size(54, 13);
			this->NOM->TabIndex = 7;
			this->NOM->Text = L"NOMBRE";
			// 
			// nombreClienteBTX
			// 
			this->nombreClienteBTX->Location = System::Drawing::Point(227, 101);
			this->nombreClienteBTX->Name = L"nombreClienteBTX";
			this->nombreClienteBTX->Size = System::Drawing::Size(126, 20);
			this->nombreClienteBTX->TabIndex = 8;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(26, 598);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(832, 144);
			this->dataGridView1->TabIndex = 9;
			// 
			// FACTURACION
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(870, 754);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->nombreClienteBTX);
			this->Controls->Add(this->NOM);
			this->Controls->Add(this->buscadorClienteBTN);
			this->Controls->Add(this->buscadorClienteBTX);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->stockBTN);
			this->Controls->Add(this->proveedoresBTN);
			this->Controls->Add(this->empleadosBTN);
			this->Controls->Add(this->clienteBTN);
			this->Name = L"FACTURACION";
			this->Text = L"FACTURACION";
			this->Load += gcnew System::EventHandler(this, &FACTURACION::FACTURACION_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void FACTURACION_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	   private: System::Void proveedoresBTN_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void empleadosBTN_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void clienteBTN_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void stockBTN_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buscadorClienteBTN_Click(System::Object^ sender, System::EventArgs^ e);
};
}
