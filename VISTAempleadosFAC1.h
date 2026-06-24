#pragma once

namespace FACPelisvistas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de VISTAempleadosFAC
	/// </summary>
	public ref class VISTAempleadosFAC : public System::Windows::Forms::Form
	{
	public:
		VISTAempleadosFAC(void)
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
		~VISTAempleadosFAC()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// VISTAempleadosFAC
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(703, 696);
			this->Name = L"VISTAempleadosFAC";
			this->Text = L"VISTAempleadosFAC";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
