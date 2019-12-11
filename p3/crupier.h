#ifndef CRUPIER_H
#define CRUPIER_H

#include "persona.h"
#include <string>

class Crupier : public Persona {
    private:
        std::string codigo_;

    public:
        Crupier(
            std::string DNI,
            std::string codigo,
            std::string nombre="",
            std::string apellidos="",
            int edad = 0,
            std::string direccion="",
            std::string localidad="",
            std::string provincia="",
            std::string pais=""
        ) : Persona(DNI, nombre, apellidos, edad, direccion, localidad, provincia, pais) {
            codigo_ = codigo;
        };

        std::string getCodigo() const { return codigo_; }
        void setCodigo(std::string codigo) { codigo_ = codigo; }
};

#endif