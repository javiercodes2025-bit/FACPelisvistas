// BDDc.cpp Esta es la especificacion de la estructura
#include <iostream>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/prepared_statement.h>
#include "peliVAR.h"


/*Después, cuando esto funcione, recién agregás:

documento
email
teléfono
dirección

porque ahí ya vas a necesitar 5 INSERT más y varios LAST_INSERT_ID().
*/

conexionCls::conexionCls(std::string nombreT, std::string apellidoT, std::string passwordT, std::string  rolT, std::string  numeroDocumentoT, std::string  tipoDocumentoT,
	std::string  correoT, std::string  telefonoT, std::string  calleT,
	std::string  numeroT, std::string  ciudadT, std::string  provinciaT) {

	this->nombre = nombreT;
	this->apellido = apellidoT;
	this->password = passwordT;
	this->rol = rolT;
	this->numeroDocumento = numeroDocumentoT;
	this->tipoDocumento = tipoDocumentoT;
	this->correo = correoT;
	this->telefono = telefonoT;
	this->calle = calleT;
	this->numero = numeroT;
	this->ciudad = ciudadT;
	this->provincia = provinciaT;
	
};

using namespace std;
sql::Connection* BDDins = nullptr;
sql::PreparedStatement* pstit;


void conexionCls::conectVoid() {
	sql::ConnectOptionsMap	BDD;
	BDD["hostName"] = "tcp://127.0.0.1";
	BDD["port"] = 3306;
	BDD["userName"] = "root";
	BDD["password"] = "";
	BDD["OPT_RECONNECT"] = true;

	// SI NO LO SOLTAS... NO TE DEJA SEGUIR(Por el primer dato);
	BDD["OPT_SSL_MODE"] = sql::SSL_MODE_DISABLED;

	try {
		sql::mysql::MySQL_Driver* driver =
			sql::mysql::get_mysql_driver_instance();
		BDDins = driver->connect(BDD);
		// NOMBRE  BDD
		BDDins->setSchema("sispelisC");

		//if (BDDins && !BDDins->isClosed()) {}
		std::cout << "Conexion exitosa" << std::endl;

	}
	catch (sql::SQLException& e) {
		std::cerr << "Error de SQL: " << e.what() << std::endl;
	}


};

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



		//FALTA EL 
		/*quedan en NULL, después de insertar en las tablas intermedias hacés:

		UPDATE persona
			SET fk_perXdocu = ? ,
			fk_perXgmail = ? ,
			fk_perXtele = ? ,
			fk_perXdir = ?
			WHERE id_persona = ? ; */
			//----------------------------------------------------------------------
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
			"(calle, numero, ciudad, provincia) "
			"VALUES (?, ?, ?, ?)");
		psDir->setString(1, sql::SQLString(calle));
		psDir->setString(2, sql::SQLString(numero));
		psDir->setString(3, sql::SQLString(ciudad));
		psDir->setString(4, sql::SQLString(provincia));

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

/*


CREATE TABLE personaXdocumento(
	id_perXdocu INT PRIMARY KEY AUTO_INCREMENT,
	fk_persona INT,
	fk_documento INT,

	FOREIGN KEY (fk_persona)
		REFERENCES persona(id_persona),

	FOREIGN KEY (fk_documento)
		REFERENCES documento(id_documento)
);

CREATE TABLE personaXemail(
	id_perXemail INT PRIMARY KEY AUTO_INCREMENT,
	fk_persona int,
	fk_email    int,

FOREIGN KEY (fk_persona)
		REFERENCES persona(id_persona),
FOREIGN KEY (fk_email)
		REFERENCES email(id_email)


);


CREATE TABLE personaXtelefonos(
	id_perXtel INT PRIMARY KEY AUTO_INCREMENT,
	fk_persona int,
	fk_telefono int,

FOREIGN KEY (fk_persona)
		REFERENCES persona(id_persona),
FOREIGN KEY (fk_telefono)
		REFERENCES telefonos(id_telefono)

);

CREATE TABLE personaXdireccion(
	id_perXdire INT PRIMARY KEY AUTO_INCREMENT,
	fk_persona INT,
	fk_direccion INT,
	FOREIGN KEY (fk_persona)
		REFERENCES persona(id_persona),

	FOREIGN KEY (fk_direccion)
		REFERENCES direccion(id_direccion)
);*/


// INSERT TABLA INTERMEDIA??? 
/* 	sql::PreparedStatement* psEmp =
		BDDins->prepareStatement(
			"INSERT INTO XX"
			"(fk_persona, XX, XX, XX)"
			" VALUES (?, ?, ?, ?)");

	psEmp->setInt(1, idPersona);
	psEmp->setString(2, XX);
	psEmp->setString(3, XX);
	psEmp->setInt(4, XX);

	psEmp->executeUpdate();

	delete psEmp;

	cout << " insertado correctamente" << endl; */

	/* 

sql::ResultSet* conexionCls::selectEmpleado() {

	try {

		if (!BDDins || BDDins->isClosed())
			conectVoid();

		sql::PreparedStatement* ps =
			BDDins->prepareStatement(

				"SELECT xx xx "
				

			);

		return ps->executeQuery();

	}
	catch (sql::SQLException& e) {

		cout << e.what() << endl;
		//return nullptr;

	}
}
	
*/
