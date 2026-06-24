#pragma once
#include "peliVAR.h"

#include <msclr/marshal_cppstd.h>
using namespace  std;
/* para q and�  los cambios de vistas... en BTN
#include <".h">
#include <".h">
#include <".h">
#include <".h"> */


void cargarPeliculas(System::Windows::Forms::DataGridView^ grid);
void eliminarPelicula(int id);
void ingresarPelicula(const std::string& titulo, int anio, int duracion,
    double precio, int descuento, int cantidad);
void actualizarPelicula(int id, const std::string& titulo, int anio, int duracion,
    double precio, int descuento, int cantidad);

ref class CLIENTES;
ref class EMPLEADOS;

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
			idSeleccionada = 0;
			cargarPeliculas(this->table1);
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
	private: System::Windows::Forms::TextBox^ idpeliculaTBX;


	private: System::Windows::Forms::TextBox^ tituloTBX;

	private: System::Windows::Forms::TextBox^ anioTBX;
	private: System::Windows::Forms::TextBox^ duraTBX;
	private: System::Windows::Forms::TextBox^ precTBX;






	private: System::Windows::Forms::DataGridView^ table1;
	private: System::Windows::Forms::Button^ emplBTN;
	private: System::Windows::Forms::TextBox^ canTBX;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ decuentoXproductoTBX;
	private: int idSeleccionada;



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
			this->idpeliculaTBX = (gcnew System::Windows::Forms::TextBox());
			this->tituloTBX = (gcnew System::Windows::Forms::TextBox());
			this->anioTBX = (gcnew System::Windows::Forms::TextBox());
			this->duraTBX = (gcnew System::Windows::Forms::TextBox());
			this->precTBX = (gcnew System::Windows::Forms::TextBox());
			this->table1 = (gcnew System::Windows::Forms::DataGridView());
			this->emplBTN = (gcnew System::Windows::Forms::Button());
			this->canTBX = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->decuentoXproductoTBX = (gcnew System::Windows::Forms::TextBox());
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
			this->label1->Location = System::Drawing::Point(36, 69);
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
			this->label3->Size = System::Drawing::Size(33, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"ANIO";
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
			this->label5->Location = System::Drawing::Point(307, 174);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(47, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"PRECIO";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(307, 220);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(62, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"CANTIDAD";
			// 
			// idpeliculaTBX
			// 
			this->idpeliculaTBX->Location = System::Drawing::Point(39, 86);
			this->idpeliculaTBX->Name = L"idpeliculaTBX";
			this->idpeliculaTBX->ReadOnly = true;
			this->idpeliculaTBX->Size = System::Drawing::Size(253, 20);
			this->idpeliculaTBX->TabIndex = 14;
			this->idpeliculaTBX->TextChanged += gcnew System::EventHandler(this, &STOCK::idTBX_TextChanged);
			// 
			// tituloTBX
			// 
			this->tituloTBX->Location = System::Drawing::Point(39, 197);
			this->tituloTBX->Name = L"tituloTBX";
			this->tituloTBX->Size = System::Drawing::Size(253, 20);
			this->tituloTBX->TabIndex = 15;
			this->tituloTBX->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &STOCK::tituloTBX_KeyPress);
			this->tituloTBX->TextChanged += gcnew System::EventHandler(this, &STOCK::tituTBX_TextChanged);
			// 
			// anioTBX
			// 
			this->anioTBX->Location = System::Drawing::Point(39, 236);
			this->anioTBX->Name = L"anioTBX";
			this->anioTBX->Size = System::Drawing::Size(253, 20);
			this->anioTBX->TabIndex = 16;
			this->anioTBX->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &STOCK::anioTBX_KeyPress);
			this->anioTBX->TextChanged += gcnew System::EventHandler(this, &STOCK::anioTBX_TextChanged);
			// 
			// duraTBX
			// 
			this->duraTBX->Location = System::Drawing::Point(39, 278);
			this->duraTBX->Name = L"duraTBX";
			this->duraTBX->Size = System::Drawing::Size(253, 20);
			this->duraTBX->TabIndex = 17;
			this->duraTBX->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &STOCK::duraTBX_KeyPress);
			this->duraTBX->TextChanged += gcnew System::EventHandler(this, &STOCK::duraTBX_TextChanged);
			// 
			// precTBX
			// 
			this->precTBX->Location = System::Drawing::Point(310, 190);
			this->precTBX->Name = L"precTBX";
			this->precTBX->Size = System::Drawing::Size(253, 20);
			this->precTBX->TabIndex = 18;
			this->precTBX->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &STOCK::precTBX_KeyPress);
			this->precTBX->TextChanged += gcnew System::EventHandler(this, &STOCK::precTBX_TextChanged);
			// 
			// table1
			// 
			this->table1->AllowUserToAddRows = false;
			this->table1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->table1->Location = System::Drawing::Point(12, 349);
			this->table1->Name = L"table1";
			this->table1->Size = System::Drawing::Size(762, 221);
			this->table1->TabIndex = 21;
			this->table1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &STOCK::table1_CellClick);
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
			this->canTBX->Location = System::Drawing::Point(310, 236);
			this->canTBX->Name = L"canTBX";
			this->canTBX->Size = System::Drawing::Size(253, 20);
			this->canTBX->TabIndex = 19;
			this->canTBX->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &STOCK::canTBX_KeyPress);
			this->canTBX->TextChanged += gcnew System::EventHandler(this, &STOCK::canTBX_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(307, 259);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(101, 13);
			this->label7->TabIndex = 24;
			this->label7->Text = L"decuentoXproducto";
			// 
			// decuentoXproductoTBX
			// 
			this->decuentoXproductoTBX->Location = System::Drawing::Point(310, 277);
			this->decuentoXproductoTBX->Name = L"decuentoXproductoTBX";
			this->decuentoXproductoTBX->Size = System::Drawing::Size(253, 20);
			this->decuentoXproductoTBX->TabIndex = 25;
			this->decuentoXproductoTBX->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &STOCK::decuentoXproductoTBX_KeyPress);
			// 
			// STOCK
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(786, 582);
			this->Controls->Add(this->decuentoXproductoTBX);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->emplBTN);
			this->Controls->Add(this->table1);
			this->Controls->Add(this->canTBX);
			this->Controls->Add(this->precTBX);
			this->Controls->Add(this->duraTBX);
			this->Controls->Add(this->anioTBX);
			this->Controls->Add(this->tituloTBX);
			this->Controls->Add(this->idpeliculaTBX);
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

	private: System::Void cliBTN_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void provBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void emplBTN_Click(System::Object^ sender, System::EventArgs^ e);


	private: System::Void ingrBTN_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			std::string titulo = msclr::interop::marshal_as<std::string>(tituloTBX->Text);
			if (titulo.empty()) {
				MessageBox::Show("Ingrese un titulo");
				return;
			}

			int anio = 0;
			if (!String::IsNullOrWhiteSpace(anioTBX->Text))
				anio = Int32::Parse(anioTBX->Text);

			if (anio != 0 && (anio < 1800 || anio > 2026)) {
				MessageBox::Show("El anio debe estar entre 1800 y 2026");
				return;
			}

			int duracion = 0;
			if (!String::IsNullOrWhiteSpace(duraTBX->Text))
				duracion = Int32::Parse(duraTBX->Text);

			if (duracion <= 0) {
				MessageBox::Show("La duracion debe ser mayor a 0");
				return;
			}

			double precio = 0.0;
			if (!String::IsNullOrWhiteSpace(precTBX->Text))
				precio = Double::Parse(precTBX->Text);

			if (precio < 0) {
				MessageBox::Show("El precio no puede ser negativo");
				return;
			}

			int descuento = 0;
			if (!String::IsNullOrWhiteSpace(decuentoXproductoTBX->Text))
				descuento = Int32::Parse(decuentoXproductoTBX->Text);

			if (descuento < 0 || descuento > 100) {
				MessageBox::Show("El descuento debe estar entre 0 y 100");
				return;
			}

			int cantidad = 0;
			if (!String::IsNullOrWhiteSpace(canTBX->Text))
				cantidad = Int32::Parse(canTBX->Text);

			ingresarPelicula(titulo, anio, duracion, precio, descuento, cantidad);
			MessageBox::Show("Pelicula ingresada correctamente");

			idSeleccionada = 0;
			idpeliculaTBX->Text = L"";
			tituloTBX->Text = L"";
			anioTBX->Text = L"";
			duraTBX->Text = L"";
			precTBX->Text = L"";
			decuentoXproductoTBX->Text = L"";
			canTBX->Text = L"";

			cargarPeliculas(this->table1);
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void eliBTN_Click(System::Object^ sender, System::EventArgs^ e) {
		if (idSeleccionada == 0) {
			MessageBox::Show("Seleccione una pelicula en la tabla");
			return;
		}

		System::Windows::Forms::DialogResult res = MessageBox::Show("Eliminar esta pelicula?", "Confirmar",
			MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
		if (res == System::Windows::Forms::DialogResult::Yes) {
			eliminarPelicula(idSeleccionada);
			

			idSeleccionada = 0;
			idpeliculaTBX->Text = L"";
			tituloTBX->Text = L"";
			anioTBX->Text = L"";
			duraTBX->Text = L"";
			precTBX->Text = L"";
			decuentoXproductoTBX->Text = L"";
			canTBX->Text = L"";

			cargarPeliculas(this->table1);
		}
	}
	private: System::Void modiBTN_Click(System::Object^ sender, System::EventArgs^ e) {
		if (idSeleccionada == 0) {
			MessageBox::Show("Seleccione una pelicula en la tabla");
			return;
		}

		try {
			std::string titulo = msclr::interop::marshal_as<std::string>(tituloTBX->Text);
			int anio = String::IsNullOrWhiteSpace(anioTBX->Text) ? 0 : Int32::Parse(anioTBX->Text);

			if (anio != 0 && (anio < 1800 || anio > 2026)) {
				MessageBox::Show("El anio debe estar entre 1800 y 2026");
				return;
			}

			int duracion = String::IsNullOrWhiteSpace(duraTBX->Text) ? 0 : Int32::Parse(duraTBX->Text);

			if (duracion <= 0) {
				MessageBox::Show("La duracion debe ser mayor a 0");
				return;
			}

			double precio = String::IsNullOrWhiteSpace(precTBX->Text) ? 0.0 : Double::Parse(precTBX->Text);

			if (precio < 0) {
				MessageBox::Show("El precio no puede ser negativo");
				return;
			}

			int descuento = String::IsNullOrWhiteSpace(decuentoXproductoTBX->Text) ? 0 : Int32::Parse(decuentoXproductoTBX->Text);

			if (descuento < 0 || descuento > 100) {
				MessageBox::Show("El descuento debe estar entre 0 y 100");
				return;
			}

			int cantidad = String::IsNullOrWhiteSpace(canTBX->Text) ? 0 : Int32::Parse(canTBX->Text);

			actualizarPelicula(idSeleccionada, titulo, anio, duracion, precio, descuento, cantidad);
			

			idSeleccionada = 0;
			idpeliculaTBX->Text = L"";
			tituloTBX->Text = L"";
			anioTBX->Text = L"";
			duraTBX->Text = L"";
			precTBX->Text = L"";
			decuentoXproductoTBX->Text = L"";
			canTBX->Text = L"";

			cargarPeliculas(this->table1);
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void table1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0) return;

		DataGridViewRow^ row = this->table1->Rows[e->RowIndex];

		idSeleccionada = (int)row->Cells["ID"]->Value;
		idpeliculaTBX->Text = idSeleccionada.ToString();
		tituloTBX->Text = row->Cells["Titulo"]->Value != nullptr ? row->Cells["Titulo"]->Value->ToString() : L"";
		anioTBX->Text = row->Cells["Anio"]->Value != nullptr ? row->Cells["Anio"]->Value->ToString() : L"";
		duraTBX->Text = row->Cells["Duracion"]->Value != nullptr ? row->Cells["Duracion"]->Value->ToString() : L"";
		precTBX->Text = row->Cells["Precio"]->Value != nullptr ? row->Cells["Precio"]->Value->ToString() : L"";
		decuentoXproductoTBX->Text = row->Cells["Descuento"]->Value != nullptr ? row->Cells["Descuento"]->Value->ToString() : L"";
		canTBX->Text = row->Cells["Cantidad"]->Value != nullptr ? row->Cells["Cantidad"]->Value->ToString() : L"";
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
	private: System::Void decuentoXproductoTBX_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
	private: System::Void precTBX_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '.' && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
	private: System::Void anioTBX_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
	private: System::Void duraTBX_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
	private: System::Void tituloTBX_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsLetterOrDigit(e->KeyChar) && e->KeyChar != ' ' && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
	private: System::Void canTBX_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
		}
	}


};



}
