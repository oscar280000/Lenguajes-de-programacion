#include <iostream>
#include <string>

// Funcion para obtener la primera vocal interna de una cadena de texto 
char ObtenerPrimeraVocalInterna(const std::string& str) {
    for (size_t i = 1; i < str.length(); ++i) {
        char c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')

        return c;
    }
    return 'X'; //Si no se encuentra ninguna vocal intern, se usa una X
}
// Funcion principal para calcular el RFC
std:: string calcularRFC(const std::string& Nombre, const std::string& ApellidoPaterno, const std::string& ApellidoMaterno, const std::string& FechaNacimiento){
    std::string rfc; 

    // Se obtiene la letra inicial y la primera vocal interna del ApellidoPaterno
    char LetraInicial = ApellidoPaterno[0];
    char PrimeraVocalInterna = ObtenerPrimeraVocalInterna(ApellidoPaterno);

    // Se obtiene la inicial del apellido materno o se usa una 'X' si no hay 
    char InicialApellidoMaterno = (!ApellidoMaterno.empty()) ? ApellidoMaterno[0] : 'X';

    // Se obtiene la inicial del primer nombre o se una 'X' si no hay 
    char InicialNombre = Nombre[0];

    // Se obtiene los dos ultimos digitos del año de fechadenacimiento
    std::string Año = FechaNacimiento.substr(2, 2);

    // Se obtiene el mes y el dia de FechaNacimiento
    std::string Mes = FechaNacimiento.substr(5, 2);
    std::string Dia = FechaNacimiento.substr(8, 2);

    // Se construye el RFC
    rfc = LetraInicial;
    rfc += PrimeraVocalInterna;
    rfc += InicialApellidoMaterno;
    rfc += InicialNombre;
    rfc += Año;
    rfc += Mes;
    rfc += Dia;
    return rfc; 
}
int main () {
    std::string Nombre, ApellidoPaterno, ApellidoMaterno, FechaNacimiento;

    std::cout << "Ingresa el nombre: ";
    std::getline(std::cin, Nombre);

    std::cout << "Ingrese el apellido paterno: ";
    std::getline(std::cin, ApellidoPaterno);

    std::cout << "Ingrese el apellido materno (Si no tiene, presione la tecla enter): ";
    std::getline(std::cin, ApellidoMaterno);

    std::cout <<"Ingrese la fecha de nacimiento (YYYY-MM-DD): ";
    std::getline(std::cin, FechaNacimiento);
    
    std::string rfc = calcularRFC(Nombre, ApellidoPaterno, ApellidoMaterno, FechaNacimiento);
    std::cout << "RFC: " << rfc << std::endl;

    return 0;
}