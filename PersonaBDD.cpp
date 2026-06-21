#include <iostream>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/prepared_statement.h>
#include "peliVAR.h"

using namespace std;

void conexionCls::insertarPersona() {
	try {

		if (!BDDins || BDDins->isClosed())
			conectVoid();

		// INSERT PERSONA
		sql::PreparedStatement* ps = BDDins->prepareStatement(

			"INSERT INTO persona "
			"(nombre, apellido, password, rol) "
			"VALUES (?, ?, ?, ?)"

		);

		ps->setString(1, sql::SQLString(nombre));
		ps->setString(2, sql::SQLString(apellido));
		ps->setString(3, sql::SQLString(password));
		ps->setString(4, sql::SQLString(rol));

		ps->executeUpdate();

		delete ps;

		// OBTENER ID GENERADO
		sql::Statement* stmt = BDDins->createStatement();
		sql::ResultSet* rs =
			stmt->executeQuery("SELECT LAST_INSERT_ID()");
		int idPersona = 0;
		if (rs->next())
			idPersona = rs->getInt(1);
		delete rs;
		delete stmt;



			// DOCUMENTO
		sql::PreparedStatement* psDoc =
			BDDins->prepareStatement(
				"INSERT INTO documento(numero_documento, tipo) "
				"VALUES (?, ?)");

		psDoc->setString(1, sql::SQLString(numeroDocumento));
		psDoc->setString(2, sql::SQLString(tipoDocumento));
		psDoc->executeUpdate();
		delete psDoc;


		// ID DOCUMENTO
		stmt = BDDins->createStatement();
		rs = stmt->executeQuery("SELECT LAST_INSERT_ID()");

		int idDocumento = 0;
		if (rs->next())
			idDocumento = rs->getInt(1);

		delete rs;
		delete stmt;

		// PERSONA X DOCUMENTO
		sql::PreparedStatement* psPerDoc =
			BDDins->prepareStatement(
				"INSERT INTO personaXdocumento(fk_empleado, fk_persona) "
				"VALUES (?, ?)");

		psPerDoc->setInt(1, idPersona);
		psPerDoc->setInt(2, idDocumento);
		psPerDoc->executeUpdate();
		delete psPerDoc;

		//----------------------------------------------------------------------


		// EMAIL
		sql::PreparedStatement* psEmail = BDDins->prepareStatement(
			"INSERT INTO email(correo) VALUES (?)");

		psEmail->setString(1, sql::SQLString(correo));
		psEmail->executeUpdate();
		delete psEmail;



		// ID EMAIL
		stmt = BDDins->createStatement();
		rs = stmt->executeQuery("SELECT LAST_INSERT_ID()");

		int idEmail = 0;
		if (rs->next())
			idEmail = rs->getInt(1);

		delete rs;
		delete stmt;

		// PERSONA X EMAIL
		sql::PreparedStatement* psPerEmail =
			BDDins->prepareStatement(
				"INSERT INTO personaXemail(fk_persona, fk_email) "
				"VALUES (?, ?)");

		psPerEmail->setInt(1, idPersona);
		psPerEmail->setInt(2, idEmail);
		psPerEmail->executeUpdate();
		delete psPerEmail;
		//----------------------------------------------------------------------

		// TELEFONO
		sql::PreparedStatement* psTel = BDDins->prepareStatement(
			"INSERT INTO telefonos(numero) VALUES (?)");

		psTel->setString(1, sql::SQLString(telefono));
		psTel->executeUpdate();
		delete psTel;


		// ID TELEFONO
		stmt = BDDins->createStatement();
		rs = stmt->executeQuery("SELECT LAST_INSERT_ID()");

		int idTelefono = 0;
		if (rs->next())
			idTelefono = rs->getInt(1);

		delete rs;
		delete stmt;

		// PERSONA X TELEFONO
		sql::PreparedStatement* psPerTel =
			BDDins->prepareStatement(
				"INSERT INTO personaXtelefonos(fk_persona, fk_telefono) "
				"VALUES (?, ?)");

		psPerTel->setInt(1, idPersona);
		psPerTel->setInt(2, idTelefono);
		psPerTel->executeUpdate();
		delete psPerTel;



		//----------------------------------------------------------------------
		// DIRECCION
		sql::PreparedStatement* psDir = BDDins->prepareStatement(
			"INSERT INTO direccion"
			"(calle, numero, ciudad) "
			"VALUES (?, ?, ?)");
		psDir->setString(1, sql::SQLString(calle));
		psDir->setString(2, sql::SQLString(numero));
		psDir->setString(3, sql::SQLString(ciudad));
		

		psDir->executeUpdate();
		delete psDir;


		// ID DIRECCION
		stmt = BDDins->createStatement();
		rs = stmt->executeQuery("SELECT LAST_INSERT_ID()");

		int idDireccion = 0;
		if (rs->next())
			idDireccion = rs->getInt(1);

		delete rs;
		delete stmt;

		// PERSONA X DIRECCION
		sql::PreparedStatement* psPerDir =
			BDDins->prepareStatement(
				"INSERT INTO personaXdireccion(fk_persona, fk_direccion) "
				"VALUES (?, ?)");

		psPerDir->setInt(1, idPersona);
		psPerDir->setInt(2, idDireccion);
		psPerDir->executeUpdate();
		delete psPerDir;

		//----------------------------------------------------------------------
		cout << "Persona registrada correctamente" << endl;
	}
	catch (sql::SQLException& e) {
		cout << e.what() << endl;
	}
}
