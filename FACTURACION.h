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
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ buscarProBTN;
	private: System::Windows::Forms::TextBox^ CodigoBarraTBX;
	private: System::Windows::Forms::TextBox^ stockTBX;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ precioTBX;
	private: System::Windows::Forms::TextBox^ nombrepeliTBX;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ descuentoXproducBTX;
	private: System::Windows::Forms::TextBox^ cantidadTBX;
	private: System::Windows::Forms::TextBox^ descuentoGENERAL;
	private: System::Windows::Forms::Button^ calcularBTN;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ subtotalTBX;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ totalTBX;
	private: System::Windows::Forms::Label^ label10;



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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buscarProBTN = (gcnew System::Windows::Forms::Button());
			this->CodigoBarraTBX = (gcnew System::Windows::Forms::TextBox());
			this->stockTBX = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->precioTBX = (gcnew System::Windows::Forms::TextBox());
			this->nombrepeliTBX = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->descuentoXproducBTX = (gcnew System::Windows::Forms::TextBox());
			this->cantidadTBX = (gcnew System::Windows::Forms::TextBox());
			this->descuentoGENERAL = (gcnew System::Windows::Forms::TextBox());
			this->calcularBTN = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->subtotalTBX = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->totalTBX = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// clienteBTN
			// 
			this->clienteBTN->Location = System::Drawing::Point(26, 39);
			this->clienteBTN->Name = L"clienteBTN";
			this->clienteBTN->Size = System::Drawing::Size(184, 23);
			this->clienteBTN->TabIndex = 0;
			this->clienteBTN->Text = L"CLIENTES";
			this->clienteBTN->UseVisualStyleBackColor = true;
			this->clienteBTN->Click += gcnew System::EventHandler(this, &FACTURACION::clienteBTN_Click);
			// 
			// empleadosBTN
			// 
			this->empleadosBTN->Location = System::Drawing::Point(227, 39);
			this->empleadosBTN->Name = L"empleadosBTN";
			this->empleadosBTN->Size = System::Drawing::Size(201, 23);
			this->empleadosBTN->TabIndex = 1;
			this->empleadosBTN->Text = L"EMPLEADOS";
			this->empleadosBTN->UseVisualStyleBackColor = true;
			this->empleadosBTN->Click += gcnew System::EventHandler(this, &FACTURACION::empleadosBTN_Click);
			// 
			// proveedoresBTN
			// 
			this->proveedoresBTN->Location = System::Drawing::Point(444, 39);
			this->proveedoresBTN->Name = L"proveedoresBTN";
			this->proveedoresBTN->Size = System::Drawing::Size(201, 23);
			this->proveedoresBTN->TabIndex = 2;
			this->proveedoresBTN->Text = L"PROVEEDORES";
			this->proveedoresBTN->UseVisualStyleBackColor = true;
			this->proveedoresBTN->Click += gcnew System::EventHandler(this, &FACTURACION::proveedoresBTN_Click);
			// 
			// stockBTN
			// 
			this->stockBTN->Location = System::Drawing::Point(651, 39);
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
			this->label1->Location = System::Drawing::Point(26, 100);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"INDETIFICACION";
			// 
			// buscadorClienteBTX
			// 
			this->buscadorClienteBTX->Location = System::Drawing::Point(29, 128);
			this->buscadorClienteBTX->Name = L"buscadorClienteBTX";
			this->buscadorClienteBTX->Size = System::Drawing::Size(181, 20);
			this->buscadorClienteBTX->TabIndex = 5;
			// 
			// buscadorClienteBTN
			// 
			this->buscadorClienteBTN->Location = System::Drawing::Point(359, 126);
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
			this->NOM->Location = System::Drawing::Point(224, 112);
			this->NOM->Name = L"NOM";
			this->NOM->Size = System::Drawing::Size(54, 13);
			this->NOM->TabIndex = 7;
			this->NOM->Text = L"NOMBRE";
			// 
			// nombreClienteBTX
			// 
			this->nombreClienteBTX->Location = System::Drawing::Point(227, 128);
			this->nombreClienteBTX->Name = L"nombreClienteBTX";
			this->nombreClienteBTX->ReadOnly = true;
			this->nombreClienteBTX->Size = System::Drawing::Size(126, 20);
			this->nombreClienteBTX->TabIndex = 8;
			this->nombreClienteBTX->Text = L"SINCUENTA";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(26, 598);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(832, 144);
			this->dataGridView1->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 176);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"CodigoBarra";
			// 
			// buscarProBTN
			// 
			this->buscarProBTN->Location = System::Drawing::Point(359, 191);
			this->buscarProBTN->Name = L"buscarProBTN";
			this->buscarProBTN->Size = System::Drawing::Size(99, 23);
			this->buscarProBTN->TabIndex = 11;
			this->buscarProBTN->Text = L"Buscar";
			this->buscarProBTN->UseVisualStyleBackColor = true;
			this->buscarProBTN->Click += gcnew System::EventHandler(this, &FACTURACION::buscarProBTN_Click);
			// 
			// CodigoBarraTBX
			// 
			this->CodigoBarraTBX->Location = System::Drawing::Point(32, 191);
			this->CodigoBarraTBX->Name = L"CodigoBarraTBX";
			this->CodigoBarraTBX->Size = System::Drawing::Size(252, 20);
			this->CodigoBarraTBX->TabIndex = 12;
			// 
			// stockTBX
			// 
			this->stockTBX->Location = System::Drawing::Point(29, 249);
			this->stockTBX->Name = L"stockTBX";
			this->stockTBX->ReadOnly = true;
			this->stockTBX->Size = System::Drawing::Size(255, 20);
			this->stockTBX->TabIndex = 13;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(29, 233);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(43, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"STOCK";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(29, 276);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 13);
			this->label4->TabIndex = 15;
			this->label4->Text = L"PRECIO";
			// 
			// precioTBX
			// 
			this->precioTBX->Location = System::Drawing::Point(29, 292);
			this->precioTBX->Name = L"precioTBX";
			this->precioTBX->ReadOnly = true;
			this->precioTBX->Size = System::Drawing::Size(255, 20);
			this->precioTBX->TabIndex = 16;
			// 
			// nombrepeliTBX
			// 
			this->nombrepeliTBX->Location = System::Drawing::Point(32, 413);
			this->nombrepeliTBX->Name = L"nombrepeliTBX";
			this->nombrepeliTBX->ReadOnly = true;
			this->nombrepeliTBX->Size = System::Drawing::Size(252, 20);
			this->nombrepeliTBX->TabIndex = 17;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(32, 394);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(69, 13);
			this->label5->TabIndex = 18;
			this->label5->Text = L"N.PELICULA";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(26, 319);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(103, 13);
			this->label6->TabIndex = 19;
			this->label6->Text = L"DecuentoXproducto";
			// 
			// descuentoXproducBTX
			// 
			this->descuentoXproducBTX->Location = System::Drawing::Point(29, 335);
			this->descuentoXproducBTX->Name = L"descuentoXproducBTX";
			this->descuentoXproducBTX->Size = System::Drawing::Size(255, 20);
			this->descuentoXproducBTX->TabIndex = 20;
			// 
			// cantidadTBX
			// 
			this->cantidadTBX->Location = System::Drawing::Point(35, 458);
			this->cantidadTBX->Name = L"cantidadTBX";
			this->cantidadTBX->Size = System::Drawing::Size(255, 20);
			this->cantidadTBX->TabIndex = 21;
			// 
			// descuentoGENERAL
			// 
			this->descuentoGENERAL->Location = System::Drawing::Point(600, 348);
			this->descuentoGENERAL->Name = L"descuentoGENERAL";
			this->descuentoGENERAL->Size = System::Drawing::Size(255, 20);
			this->descuentoGENERAL->TabIndex = 23;
			// 
			// calcularBTN
			// 
			this->calcularBTN->Location = System::Drawing::Point(686, 414);
			this->calcularBTN->Name = L"calcularBTN";
			this->calcularBTN->Size = System::Drawing::Size(99, 23);
			this->calcularBTN->TabIndex = 29;
			this->calcularBTN->Text = L"CALCULAR";
			this->calcularBTN->UseVisualStyleBackColor = true;
			this->calcularBTN->Click += gcnew System::EventHandler(this, &FACTURACION::calcularBTN_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(35, 442);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(62, 13);
			this->label7->TabIndex = 22;
			this->label7->Text = L"CANTIDAD";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(600, 332);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(74, 13);
			this->label8->TabIndex = 24;
			this->label8->Text = L"DESCUENTO";
			// 
			// subtotalTBX
			// 
			this->subtotalTBX->Location = System::Drawing::Point(600, 388);
			this->subtotalTBX->Name = L"subtotalTBX";
			this->subtotalTBX->ReadOnly = true;
			this->subtotalTBX->Size = System::Drawing::Size(255, 20);
			this->subtotalTBX->TabIndex = 25;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(600, 372);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(64, 13);
			this->label9->TabIndex = 26;
			this->label9->Text = L"SUBTOTAL";
			// 
			// totalTBX
			// 
			this->totalTBX->Location = System::Drawing::Point(603, 458);
			this->totalTBX->Name = L"totalTBX";
			this->totalTBX->ReadOnly = true;
			this->totalTBX->Size = System::Drawing::Size(255, 20);
			this->totalTBX->TabIndex = 27;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(603, 442);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(42, 13);
			this->label10->TabIndex = 28;
			this->label10->Text = L"TOTAL";
			// 
			// FACTURACION
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(870, 754);
			this->Controls->Add(this->descuentoXproducBTX);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->nombrepeliTBX);
			this->Controls->Add(this->precioTBX);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->stockTBX);
			this->Controls->Add(this->CodigoBarraTBX);
			this->Controls->Add(this->buscarProBTN);
			this->Controls->Add(this->label2);
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
			this->Controls->Add(this->label7);
			this->Controls->Add(this->cantidadTBX);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->descuentoGENERAL);
			this->Controls->Add(this->calcularBTN);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->subtotalTBX);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->totalTBX);
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
private: System::Void buscarProBTN_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void calcularBTN_Click(System::Object^ sender, System::EventArgs^ e);
};
}
