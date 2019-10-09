#include "persona.h"
#include <string>

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

bool Persona::setEdad (int edad) {
    if (edad < 0) {
        return false;
    }
    
    edad_ = edad;
    return true;
}