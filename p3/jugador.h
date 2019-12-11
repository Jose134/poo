#ifndef JUGADOR_H
#define JUGADOR_H

#include "persona.h"
#include <list>
#include <string>

struct Apuesta {
    int tipo;
    std::string valor;
    int cantidad;
};

class Jugador : public Persona {
    private: 
        int dinero_;
        std::string codigo_;
        std::list<Apuesta> apuestas_;

    public:
        Jugador(
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
            dinero_ = 1000;
        };

        std::string getCodigo() const { return codigo_; }
        void setCodigo(std::string codigo) { codigo_ = codigo; }

        std::list<Apuesta> getApuestas() const { return apuestas_; }
        void setApuestas();

        int getDinero() const { return dinero_; }
        void setDinero(int dinero) { dinero_ = dinero; }
};

#endif