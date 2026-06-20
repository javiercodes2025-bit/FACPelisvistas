
#include <string>
#include <jdbc/cppconn/resultset.h>
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
    std::string provincia;
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
        std::string ciudad,
        std::string provincia

    );

    void insertarPersona();
    void conectVoid();
    sql::ResultSet* selectPersona();
};