// BDDc.cpp Esta es la especificacion de la estructura
#include <iostream>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/prepared_statement.h>
#include "peliVAR.h"


/*Despu�s, cuando esto funcione, reci�n agreg�s:

documento
email
tel�fono
direcci�n

porque ah� ya vas a necesitar 5 INSERT m�s y varios LAST_INSERT_ID().
*/

conexionCls::conexionCls(std::string nombreT, std::string apellidoT, std::string passwordT, std::string  rolT, std::string  numeroDocumentoT, std::string  tipoDocumentoT,
	std::string  correoT, std::string  telefonoT, std::string  calleT,
	std::string  numeroT, std::string  ciudadT) {

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
