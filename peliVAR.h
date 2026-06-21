#pragma once
#include <string>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/prepared_statement.h>

extern sql::Connection* BDDins;
extern sql::PreparedStatement* pstit;
class conexionCls {
private:

    // PERSONA
 
    std::string nombre;
    std::string apellido;
    std::string password;
    std::string rol;

    std::string numeroDocumento;
    std::string tipoDocumento;

    std::string correo;

    std::string telefono;

    std::string calle;
    std::string numero;
    std::string ciudad;
public:

    conexionCls(
        std::string nombre,
        std::string apellido,
        std::string password,
        std::string rol,

        std::string numeroDocumento,
        std::string tipoDocumento,

        std::string correo,

        std::string telefono,

        std::string calle,
        std::string numero,
        std::string ciudad
    );

    void insertarPersona();
    void conectVoid();
    sql::ResultSet* selectPersona();
};