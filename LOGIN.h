#pragma once
#include "Empleados.h"
#include "Registrar.h"

/*como harias el select.. */
namespace FACPelisVistas {
	// INSERTtableCon
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
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
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ingBTN;
	protected:

	private: System::Windows::Forms::Button^ resBTN;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ userTBX;
	private: System::Windows::Forms::TextBox^ passTBX;


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
			this->ingBTN = (gcnew System::Windows::Forms::Button());
			this->resBTN = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->userTBX = (gcnew System::Windows::Forms::TextBox());
			this->passTBX = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// ingBTN
			// 
			this->ingBTN->Location = System::Drawing::Point(83, 325);
			this->ingBTN->Name = L"ingBTN";
			this->ingBTN->Size = System::Drawing::Size(286, 23);
			this->ingBTN->TabIndex = 0;
			this->ingBTN->Text = L"Ingresar";
			this->ingBTN->UseVisualStyleBackColor = true;
			this->ingBTN->Click += gcnew System::EventHandler(this, &Login::ingBTN_Click);
			// 
			// resBTN
			// 
			this->resBTN->Location = System::Drawing::Point(398, 325);
			this->resBTN->Name = L"resBTN";
			this->resBTN->Size = System::Drawing::Size(187, 23);
			this->resBTN->TabIndex = 1;
			this->resBTN->Text = L"Registrar";
			this->resBTN->UseVisualStyleBackColor = true;
			this->resBTN->Click += gcnew System::EventHandler(this, &Login::resBTN_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(83, 132);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"USUARIO";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(83, 215);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"PASSWORD";
			// 
			// userTBX
			// 
			this->userTBX->Location = System::Drawing::Point(83, 148);
			this->userTBX->Name = L"userTBX";
			this->userTBX->Size = System::Drawing::Size(502, 20);
			this->userTBX->TabIndex = 4;
			// 
			// passTBX
			// 
			this->passTBX->Location = System::Drawing::Point(83, 241);
			this->passTBX->Name = L"passTBX";
			this->passTBX->Size = System::Drawing::Size(502, 20);
			this->passTBX->TabIndex = 5;
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(670, 486);
			this->Controls->Add(this->passTBX);
			this->Controls->Add(this->userTBX);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->resBTN);
			this->Controls->Add(this->ingBTN);
			this->Name = L"Login";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void ingBTN_Click(System::Object^ sender, System::EventArgs^ e) {
		/* Select.. A  nombre + pass con un Where a rol... */
		EMPLEADOS^ emp = gcnew EMPLEADOS;
		emp->Show();
	}


	private: System::Void resBTN_Click(System::Object^ sender, System::EventArgs^ e) {
		Registrar^ res = gcnew Registrar;
		res->Show();
	}
	};
}
