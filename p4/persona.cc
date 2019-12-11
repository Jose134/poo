#include "persona.h"
#include <string>

//Constructor
Persona::Persona (std::string dni, std::string nombre, std::string apellidos, int edad, std::string direccion, std::string localidad, std::string provincia, std::string pais) {
    dni_ = dni;
    nombre_ = nombre;
    apellidos_ = apellidos;
    edad_ = edad;
    direccion_ = direccion;
    localidad_ = localidad;
    provincia_ = provincia;
    pais_ = pais;
}
