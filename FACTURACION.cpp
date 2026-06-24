#include "FACTURACION.h"
#include "PROVEEDORES.h"
#include "Clientes.h"
#include "Empleados.h"
#include "Stock.h"
#include <msclr/marshal_cppstd.h>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/prepared_statement.h>
#include "peliVAR.h"

void FACPelisvistas::FACTURACION::proveedoresBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	FACPelisVistas::PROVEEDORES^ prov = gcnew FACPelisVistas::PROVEEDORES;
	prov->Show();
}
void FACPelisvistas::FACTURACION::empleadosBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	FACPelisVistas::EMPLEADOS^ emp = gcnew FACPelisVistas::EMPLEADOS;
	emp->Show();
}
void FACPelisvistas::FACTURACION::clienteBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	FACPelisVistas::CLIENTES^ cli = gcnew FACPelisVistas::CLIENTES;
	cli->Show();
}
void FACPelisvistas::FACTURACION::stockBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	FACPelisVistas::STOCK^ stk = gcnew FACPelisVistas::STOCK;
	stk->Show();
}
void FACPelisvistas::FACTURACION::buscadorClienteBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(buscadorClienteBTX->Text)) return;
	int idPersona;
	if (!Int32::TryParse(buscadorClienteBTX->Text, idPersona)) return;
	try {
		if (!BDDins || BDDins->isClosed()) {
			conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
			temp.conectVoid();
		}
		sql::PreparedStatement* ps = BDDins->prepareStatement(
			"SELECT p.nombre, p.apellido, p.habilitado "
			"FROM persona p "
			"WHERE p.id_persona = ?"
		);
		ps->setInt(1, idPersona);
		sql::ResultSet* rs = ps->executeQuery();
		if (rs->next()) {
			if (rs->getInt("habilitado") == 0) {
				MessageBox::Show("Existe pero habilitado = 0");
				nombreClienteBTX->Text = L"";
			} else {
				nombreClienteBTX->Text = gcnew String(rs->getString("nombre").c_str()) + " " +
					gcnew String(rs->getString("apellido").c_str());
			}
		} else {
			MessageBox::Show("Esa persona no existe.. ");
			nombreClienteBTX->Text = L"";
		}
		delete rs;
		delete ps;
	}
	catch (sql::SQLException& ex) {
		MessageBox::Show(gcnew String(ex.what()));
	}
}
void FACPelisvistas::FACTURACION::buscarProBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(CodigoBarraTBX->Text)) return;
	int idPelicula;
	if (!Int32::TryParse(CodigoBarraTBX->Text, idPelicula)) return;
	try {
		if (!BDDins || BDDins->isClosed()) {
			conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
			temp.conectVoid();
		}
		sql::PreparedStatement* ps = BDDins->prepareStatement(
			"SELECT p.titulo, p.precio, p.decuentoXproducto, s.cantidad "
			"FROM pelicula p "
			"LEFT JOIN stock s ON p.id_pelicula = s.fk_pelicula "
			"WHERE p.id_pelicula = ? AND p.habi = 1"
		);
		ps->setInt(1, idPelicula);
		sql::ResultSet* rs = ps->executeQuery();
		if (rs->next()) {
			nombrepeliTBX->Text = gcnew String(rs->getString("titulo").c_str());
			precioTBX->Text = gcnew String(rs->getString("precio").c_str());
			descuentoXproducBTX->Text = gcnew String(rs->getString("decuentoXproducto").c_str());
			if (rs->isNull("cantidad"))
				stockTBX->Text = L"0";
			else
				stockTBX->Text = gcnew String(rs->getString("cantidad").c_str());
		}
		else {
			MessageBox::Show("Esa pelicula no existe");
			nombrepeliTBX->Text = L"";
			precioTBX->Text = L"";
			descuentoXproducBTX->Text = L"";
			stockTBX->Text = L"";
		}
		delete rs;
		delete ps;
	}
	catch (sql::SQLException& ex) {
		MessageBox::Show(gcnew String(ex.what()));
	}
}
void FACPelisvistas::FACTURACION::calcularBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(cantidadTBX->Text) ||
		String::IsNullOrWhiteSpace(precioTBX->Text) ||
		String::IsNullOrWhiteSpace(stockTBX->Text)) return;
	try {
		double precio = Double::Parse(precioTBX->Text, System::Globalization::CultureInfo::InvariantCulture);
		int cantidad = Int32::Parse(cantidadTBX->Text);
		int stock = Int32::Parse(stockTBX->Text);

		if (cantidad <= 0) {
			MessageBox::Show("La cantidad debe ser mayor a 0");
			return;
		}
		if (cantidad > stock) {
			MessageBox::Show("Stock insuficiente. Disponible: " + stock);
			return;
		}

		double descProducto = 0;
		double descuento = 0;

		if (!String::IsNullOrWhiteSpace(descuentoXproducBTX->Text)) {
			descProducto = Double::Parse(descuentoXproducBTX->Text, System::Globalization::CultureInfo::InvariantCulture);
			if (descProducto < 0 || descProducto > 100) {
				MessageBox::Show("El descuentoXproducto debe estar entre 0 y 100");
				return;
			}
		}

		if (!String::IsNullOrWhiteSpace(descuentoGENERAL->Text)) {
			descuento = Double::Parse(descuentoGENERAL->Text, System::Globalization::CultureInfo::InvariantCulture);
			if (descuento < 0 || descuento > 100) {
				MessageBox::Show("El descuento debe estar entre 0 y 100");
				return;
			}
		}

		double subtotal = precio * cantidad;
		subtotal = subtotal - (subtotal * descProducto / 100.0);
		double total = subtotal - (subtotal * descuento / 100.0);

		subtotalTBX->Text = subtotal.ToString("F2");
		totalTBX->Text = total.ToString("F2");
	}
	catch (Exception^) {
		MessageBox::Show("Ingrese un numero valido...");
	}
}
void FACPelisvistas::FACTURACION::agregarBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	modificarActivo = false;
	if (String::IsNullOrWhiteSpace(CodigoBarraTBX->Text) ||
		String::IsNullOrWhiteSpace(cantidadTBX->Text) ||
		String::IsNullOrWhiteSpace(precioTBX->Text) ||
		String::IsNullOrWhiteSpace(subtotalTBX->Text) ||
		String::IsNullOrWhiteSpace(totalTBX->Text)) return;
	int idClientePersona;
	int idPelicula;
	int cantidad;
	if (!Int32::TryParse(CodigoBarraTBX->Text, idPelicula)) return;
	if (!Int32::TryParse(cantidadTBX->Text, cantidad) || cantidad <= 0) return;
	if (metodopagoCBX->SelectedIndex <= 0) {
		MessageBox::Show("Seleccione un metodo de pago");
		return;
	}
	try {
		if (!BDDins || BDDins->isClosed()) {
			conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
			temp.conectVoid();
		}

		// Buscar id_cliente solo si hay ID ingresado
		int idCliente = 0;
		if (Int32::TryParse(buscadorClienteBTX->Text, idClientePersona)) {
			sql::PreparedStatement* psCli = BDDins->prepareStatement(
				"SELECT id_cliente FROM cliente WHERE fk_persona = ?"
			);
			psCli->setInt(1, idClientePersona);
			sql::ResultSet* rsCli = psCli->executeQuery();
			if (rsCli->next())
				idCliente = rsCli->getInt("id_cliente");
			delete rsCli;
			delete psCli;
		}

		// INSERT venta
		sql::PreparedStatement* psVenta = BDDins->prepareStatement(
			"INSERT INTO venta(fk_cliente, metodo_pago, subtotal, descuento, total, NombrePro) "
			"VALUES (?, ?, ?, ?, ?, ?)"
		);
		if (idCliente > 0)
			psVenta->setInt(1, idCliente);
		else
			psVenta->setNull(1, sql::DataType::INTEGER);
		psVenta->setString(2, sql::SQLString(
			msclr::interop::marshal_as<std::string>(metodopagoCBX->Text)));
		psVenta->setString(3, sql::SQLString(
			msclr::interop::marshal_as<std::string>(subtotalTBX->Text)));
		psVenta->setString(4, sql::SQLString(
			msclr::interop::marshal_as<std::string>(
				String::IsNullOrWhiteSpace(descuentoGENERAL->Text) ? L"0" : descuentoGENERAL->Text)));
		psVenta->setString(5, sql::SQLString(
			msclr::interop::marshal_as<std::string>(totalTBX->Text)));
		psVenta->setString(6, sql::SQLString(
			msclr::interop::marshal_as<std::string>(nombrepeliTBX->Text)));
		psVenta->executeUpdate();
		delete psVenta;

		// LAST_INSERT_ID
		sql::Statement* stmt = BDDins->createStatement();
		sql::ResultSet* rsId = stmt->executeQuery("SELECT LAST_INSERT_ID()");
		int idVenta = 0;
		if (rsId->next())
			idVenta = rsId->getInt(1);
		delete rsId;
		delete stmt;

		// INSERT peliculaXventa
		sql::PreparedStatement* psPX = BDDins->prepareStatement(
			"INSERT INTO peliculaXventa(fk_venta, fk_pelicula, cantidad, DescuentoXproducto) "
			"VALUES (?, ?, ?, ?)"
		);
		psPX->setInt(1, idVenta);
		psPX->setInt(2, idPelicula);
		psPX->setInt(3, cantidad);
		psPX->setString(4, sql::SQLString(
			msclr::interop::marshal_as<std::string>(
				String::IsNullOrWhiteSpace(descuentoXproducBTX->Text) ? L"0" : descuentoXproducBTX->Text)));
		psPX->executeUpdate();
		delete psPX;

		// UPDATE stock
		sql::PreparedStatement* psStock = BDDins->prepareStatement(
			"UPDATE stock SET cantidad = cantidad - ? WHERE fk_pelicula = ?"
		);
		psStock->setInt(1, cantidad);
		psStock->setInt(2, idPelicula);
		psStock->executeUpdate();
		delete psStock;

		MessageBox::Show("Venta agregada");

		// Limpiar campos
		CodigoBarraTBX->Text = L"";
		cantidadTBX->Text = L"";
		descuentoGENERAL->Text = L"";
		subtotalTBX->Text = L"";
		totalTBX->Text = L"";
		nombrepeliTBX->Text = L"";
		precioTBX->Text = L"";
		stockTBX->Text = L"";
		descuentoXproducBTX->Text = L"";
		nombreClienteBTX->Text = L"SINCUENTA";
		buscadorClienteBTX->Text = L"";
		metodopagoCBX->SelectedIndex = 0;
		cargarVentas();

	}
	catch (sql::SQLException& ex) {
		MessageBox::Show(gcnew String(ex.what()));
	}
}
void FACPelisvistas::FACTURACION::cargarVentas() {
	try {
		if (!BDDins || BDDins->isClosed()) {
			conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
			temp.conectVoid();
		}
		sql::PreparedStatement* ps = BDDins->prepareStatement(
			"SELECT v.id_venta, v.fecha_venta, v.metodo_pago, "
			"v.subtotal, v.descuento, v.total, v.NombrePro, v.cuenta, "
			"pel.titulo, pv.cantidad "
			"FROM venta v "
			"LEFT JOIN peliculaXventa pv ON v.id_venta = pv.fk_venta "
			"LEFT JOIN pelicula pel ON pv.fk_pelicula = pel.id_pelicula "
			"WHERE v.habi = 1 "
			"ORDER BY v.id_venta DESC"
		);
		sql::ResultSet* rs = ps->executeQuery();

		DataTable^ table = gcnew DataTable("Ventas");
		table->Columns->Add("Venta ID", Int32::typeid);
		table->Columns->Add("Fecha", String::typeid);
		table->Columns->Add("Cliente", String::typeid);
		table->Columns->Add("Producto", String::typeid);
		table->Columns->Add("Cant", Int32::typeid);
		table->Columns->Add("Subtotal", String::typeid);
		table->Columns->Add("Dto", String::typeid);
		table->Columns->Add("Total", String::typeid);
		table->Columns->Add("Pago", String::typeid);

		while (rs->next()) {
			DataRow^ row = table->NewRow();
			row["Venta ID"] = rs->getInt("id_venta");
			row["Fecha"] = gcnew String(rs->getString("fecha_venta").c_str());
			row["Cliente"] = gcnew String(rs->getString("cuenta").c_str());
			row["Producto"] = gcnew String(rs->getString("titulo").c_str());
			row["Cant"] = rs->getInt("cantidad");
			row["Subtotal"] = gcnew String(rs->getString("subtotal").c_str());
			row["Dto"] = gcnew String(rs->getString("descuento").c_str());
			row["Total"] = gcnew String(rs->getString("total").c_str());
			row["Pago"] = gcnew String(rs->getString("metodo_pago").c_str());
			table->Rows->Add(row);
		}

		dataGridView1->DataSource = table;
		delete rs;
		delete ps;
	}
	catch (sql::SQLException& ex) {
		MessageBox::Show(gcnew String(ex.what()));
	}
}

void FACPelisvistas::FACTURACION::modificarBTN_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->SelectedRows->Count == 0) {
		MessageBox::Show("Seleccione una venta de la grilla");
		return;
	}

	if (!modificarActivo) {
		// --- 1er click: cargar datos ---
		int idVenta = (int)dataGridView1->SelectedRows[0]->Cells["Venta ID"]->Value;

		try {
			if (!BDDins || BDDins->isClosed()) {
				conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
				temp.conectVoid();
			}

			sql::PreparedStatement* ps = BDDins->prepareStatement(
				"SELECT v.metodo_pago, v.subtotal, v.descuento, v.total, v.NombrePro, v.cuenta, "
				"pv.fk_pelicula, pv.cantidad, pv.DescuentoXproducto, "
				"p.titulo, p.precio, s.cantidad AS stock_actual "
				"FROM venta v "
				"JOIN peliculaXventa pv ON v.id_venta = pv.fk_venta "
				"JOIN pelicula p ON pv.fk_pelicula = p.id_pelicula "
				"LEFT JOIN stock s ON pv.fk_pelicula = s.fk_pelicula "
				"WHERE v.id_venta = ?"
			);
			ps->setInt(1, idVenta);
			sql::ResultSet* rs = ps->executeQuery();

			if (rs->next()) {
				nombrepeliTBX->Text = gcnew String(rs->getString("titulo").c_str());
				precioTBX->Text = gcnew String(rs->getString("precio").c_str());
				nombreClienteBTX->Text = gcnew String(rs->getString("cuenta").c_str());
				cantidadTBX->Text = gcnew String(rs->getString("cantidad").c_str());
				descuentoXproducBTX->Text = gcnew String(rs->getString("DescuentoXproducto").c_str());
				descuentoGENERAL->Text = gcnew String(rs->getString("descuento").c_str());
				subtotalTBX->Text = gcnew String(rs->getString("subtotal").c_str());
				totalTBX->Text = gcnew String(rs->getString("total").c_str());
				stockTBX->Text = rs->isNull("stock_actual") ? L"0" : gcnew String(rs->getString("stock_actual").c_str());

				String^ metodo = gcnew String(rs->getString("metodo_pago").c_str());
				for (int i = 0; i < metodopagoCBX->Items->Count; i++) {
					if (metodopagoCBX->Items[i]->ToString() == metodo) {
						metodopagoCBX->SelectedIndex = i;
						break;
					}
				}

				idVentaModificar = idVenta;
				idPeliculaModificar = rs->getInt("fk_pelicula");
				cantidadAnterior = rs->getInt("cantidad");
				modificarActivo = true;
			}
			else {
				MessageBox::Show("No se encontraron datos de la venta");
			}
			delete rs;
			delete ps;
		}
		catch (sql::SQLException& ex) {
			MessageBox::Show(gcnew String(ex.what()));
		}
	}
	else {
		// --- 2do click: aplicar cambios ---
		int nuevaCantidad;
		if (!Int32::TryParse(cantidadTBX->Text, nuevaCantidad)) {
			MessageBox::Show("Cantidad invalida");
			return;
		}

		if (metodopagoCBX->SelectedIndex <= 0) {
			MessageBox::Show("Seleccione un metodo de pago");
			return;
		}

		try {
			if (!BDDins || BDDins->isClosed()) {
				conexionCls temp("", "", "", "", "", "", "", "", "", "", "");
				temp.conectVoid();
			}

			// Recalcular como en calcularBTN
			double precio = Double::Parse(precioTBX->Text, System::Globalization::CultureInfo::InvariantCulture);
			double descProducto = 0;
			double descuento = 0;
			if (!String::IsNullOrWhiteSpace(descuentoXproducBTX->Text))
				descProducto = Double::Parse(descuentoXproducBTX->Text, System::Globalization::CultureInfo::InvariantCulture);
			if (!String::IsNullOrWhiteSpace(descuentoGENERAL->Text))
				descuento = Double::Parse(descuentoGENERAL->Text, System::Globalization::CultureInfo::InvariantCulture);

			double subtotal = precio * nuevaCantidad;
			subtotal = subtotal - (subtotal * descProducto / 100.0);
			double total = subtotal - (subtotal * descuento / 100.0);

			// UPDATE venta
			sql::PreparedStatement* psV = BDDins->prepareStatement(
				"UPDATE venta SET metodo_pago=?, descuento=?, subtotal=?, total=?, NombrePro=? "
				"WHERE id_venta=?"
			);
			psV->setString(1, sql::SQLString(
				msclr::interop::marshal_as<std::string>(metodopagoCBX->Text)));
			psV->setString(2, sql::SQLString(
				msclr::interop::marshal_as<std::string>(
					String::IsNullOrWhiteSpace(descuentoGENERAL->Text) ? L"0" : descuentoGENERAL->Text)));
			psV->setString(3, sql::SQLString(
				msclr::interop::marshal_as<std::string>(subtotal.ToString("F2", System::Globalization::CultureInfo::InvariantCulture))));
			psV->setString(4, sql::SQLString(
				msclr::interop::marshal_as<std::string>(total.ToString("F2", System::Globalization::CultureInfo::InvariantCulture))));
			psV->setString(5, sql::SQLString(
				msclr::interop::marshal_as<std::string>(nombrepeliTBX->Text)));
			psV->setInt(6, idVentaModificar);
			psV->executeUpdate();
			delete psV;

			// UPDATE peliculaXventa (cantidad y descuento)
			sql::PreparedStatement* psPX = BDDins->prepareStatement(
				"UPDATE peliculaXventa SET cantidad=?, DescuentoXproducto=? WHERE fk_venta=?"
			);
			psPX->setInt(1, nuevaCantidad);
			psPX->setString(2, sql::SQLString(
				msclr::interop::marshal_as<std::string>(
					String::IsNullOrWhiteSpace(descuentoXproducBTX->Text) ? L"0" : descuentoXproducBTX->Text)));
			psPX->setInt(3, idVentaModificar);
			psPX->executeUpdate();
			delete psPX;

			// UPDATE stock
			sql::PreparedStatement* psStock = BDDins->prepareStatement(
				"UPDATE stock SET cantidad = cantidad - (? - ?) WHERE fk_pelicula = ?"
			);
			psStock->setInt(1, nuevaCantidad);
			psStock->setInt(2, cantidadAnterior);
			psStock->setInt(3, idPeliculaModificar);
			psStock->executeUpdate();
			delete psStock;

			MessageBox::Show("Venta modificada");

			// Limpiar
			CodigoBarraTBX->Text = L"";
			cantidadTBX->Text = L"";
			descuentoGENERAL->Text = L"";
			subtotalTBX->Text = L"";
			totalTBX->Text = L"";
			nombrepeliTBX->Text = L"";
			precioTBX->Text = L"";
			stockTBX->Text = L"";
			descuentoXproducBTX->Text = L"";
			nombreClienteBTX->Text = L"SINCUENTA";
			buscadorClienteBTX->Text = L"";
			metodopagoCBX->SelectedIndex = 0;

			modificarActivo = false;
			cargarVentas();
		}
		catch (sql::SQLException& ex) {
			MessageBox::Show(gcnew String(ex.what()));
		}
	}
}

