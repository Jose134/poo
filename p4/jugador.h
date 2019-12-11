#ifndef JUGADOR_H
#define JUGADOR_H

#include "persona.h"
#include <list>
#include <string>

//Holds information for a bet
struct Apuesta {
    int tipo;
    std::string valor;
    int cantidad;
};

//Represents a player
class Jugador : public Persona {
    private: 
        int dinero_;
        std::string codigo_;
        std::list<Apuesta> apuestas_;

    public:
        //Constructor
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

        std::string getCodigo() const { return codigo_; }        //Returns player's code
        void setCodigo(std::string codigo) { codigo_ = codigo; } //Sets player's code

        std::list<Apuesta> getApuestas() const { return apuestas_; } //Returns a list with all the bets done by the player
        void setApuestas();                                          //Reads a player's bets from his file (dni.txt)

        int getDinero() const { return dinero_; }        //Returns player's amount of money
        void setDinero(int dinero) { dinero_ = dinero; } //Sets player's amount of money
};

#endif