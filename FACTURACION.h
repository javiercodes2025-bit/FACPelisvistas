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
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
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



	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->clienteBTN = (gcnew System::Windows::Forms::Button());
			this->empleadosBTN = (gcnew System::Windows::Forms::Button());
			this->proveedoresBTN = (gcnew System::Windows::Forms::Button());
			this->stockBTN = (gcnew System::Windows::Forms::Button());
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
			// FACTURACION
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(870, 692);
			this->Controls->Add(this->stockBTN);
			this->Controls->Add(this->proveedoresBTN);
			this->Controls->Add(this->empleadosBTN);
			this->Controls->Add(this->clienteBTN);
			this->Name = L"FACTURACION";
			this->Text = L"FACTURACION";
			this->Load += gcnew System::EventHandler(this, &FACTURACION::FACTURACION_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	
private: System::Void FACTURACION_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	   private: System::Void proveedoresBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	   }

private: System::Void empleadosBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void clienteBTN_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void stockBTN_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
