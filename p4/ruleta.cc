#include "ruleta.h"
#include <fstream>
#include <list>
#include <iostream>
#include <string>

/* Adds a player to the roulette
 * Returns true on success
 * Returns false if the player or player's file already exists
 */
bool Ruleta::addJugador (Jugador jugador) {
    //Checks if the player already exists on the list
    for (Jugador j : jugadores_) {
        if (j.getDNI() == jugador.getDNI()) { 
            return false;
        }
    }

    //Adds player to the list
    jugadores_.push_back(jugador);

    //Checks if player's file exists
    std::ifstream iFile(jugador.getDNI() + ".txt");
    if (!iFile) {
        //Creates player's file
        std::ofstream oFile(jugador.getDNI() + ".txt");
        oFile.close();
        return true;
    }

    iFile.close();
    return false;
}

//Removes a player from the list (given player's dni)
int Ruleta::deleteJugador (std::string dni) {
    //Checks if list is empty
    if (jugadores_.empty()) { return -1; }

    for (auto it = jugadores_.begin(); it != jugadores_.end(); it++) {
        if (it->getDNI() == dni) {
            jugadores_.erase(it);
            return 1; //Player deleted
        }
    }

    return -2; //Player not found
}

//Removes a player from the list (given player's instance)
int Ruleta::deleteJugador (Jugador jugador) {
    //Checks if list is empty
    if (jugadores_.empty()) { return -1; }

    for (auto it = jugadores_.begin(); it != jugadores_.end(); it++) {
        if (it->getDNI() == jugador.getDNI()) {
            jugadores_.erase(it);
            return 1; //Player deleted
        }
    }

    return -2; //Player not found
}

//Saves all player's into a text file named "jugadores.txt"
void Ruleta::escribeJugadores () const {
    std::ofstream file("jugadores.txt");

    if (file) {
        for (Jugador j : jugadores_) {
            file << j.getDNI()       << ','
                 << j.getCodigo()    << ','
                 << j.getNombre()    << ','
                 << j.getApellidos() << ','
                 << j.getDireccion() << ','
                 << j.getLocalidad() << ','
                 << j.getProvincia() << ','
                 << j.getPais()      << ','
                 << j.getDinero()    << ','
                 << std::endl;
        }

        file.close();
    }
}

//Loads all the players from the file "jugadores.txt"
void Ruleta::leeJugadores () {
    std::ifstream file("jugadores.txt");

    if (file) {
        //Variables jugador
        std::string dni;
        std::string codigo;
        std::string nombre;
        std::string apellidos;
        std::string direccion;
        std::string localidad;
        std::string provincia;
        std::string pais;
        std::string dinero;

        //Read file
        while (getline(file, dni, ',')) {
            getline(file, codigo, ',');
            getline(file, nombre, ',');
            getline(file, apellidos, ',');
            getline(file, direccion, ',');
            getline(file, localidad, ',');
            getline(file, provincia, ',');
            getline(file, pais, ',');
            getline(file, dinero, '\n');


            //Constructs a player
            Jugador aux = Jugador(dni, codigo, nombre, apellidos, 0, direccion, localidad, provincia, pais);
            aux.setDinero(stoi(dinero));

            //Adds the player to the list
            jugadores_.push_back(aux);
        }

        file.close();
    }
}

//Helper function: returns the color associated to the given number
std::string Ruleta::getColor (int bola) {
    if (bola >= 1 && bola <= 10) {
        if (bola % 2 == 0) {
            return "negro";
        }
        else {
            return "rojo";
        }
    }
    else if (bola >= 11 && bola <= 18) {
        if (bola % 2 == 0) {
            return "rojo";
        }
        else {
            return "negro";
        }
    }
    else if (bola >= 19 && bola <= 28) {
        if (bola % 2 == 0) {
            return "negro";
        }
        else {
            return "rojo";
        }
    }
    else if (bola >= 29 && bola <= 36) {
        if (bola % 2 == 0) {
            return "rojo";
        }
        else {
            return "negro";
        }
    }
    else {
        return "error";
    }
}

//Reads all the bets done by the players and updates player's and bank's money
void Ruleta::getPremios () {
    std::list<Apuesta> apuestas;
    for (Jugador& j : jugadores_) {
        j.setApuestas();
        apuestas = j.getApuestas();

        for (Apuesta a : apuestas) {
            switch (a.tipo) {
                case 1: //Number bet
                    if (stoi(a.valor) == bola_) {
                        j.setDinero(j.getDinero() + 35 * a.cantidad);
                        banca_ -= 35 * a.cantidad;
                    }
                    else {
                        j.setDinero(j.getDinero() - a.cantidad);
                        banca_ += a.cantidad;
                    }

                    break;
                case 2: //Color bet

                    if (a.valor == getColor(bola_)) {
                        j.setDinero(j.getDinero() + a.cantidad);
                        banca_ -= a.cantidad; 
                    }
                    else {
                        j.setDinero(j.getDinero() - a.cantidad);
                        banca_ += a.cantidad;
                    }

                    break;
                case 3: //Parity bet

                    if (bola_ == 0) {
                        j.setDinero(j.getDinero() - a.cantidad);
                        banca_ += a.cantidad;
                    }
                    else {
                        if (a.valor == "par" && bola_ % 2 == 0) {
                            j.setDinero(j.getDinero() + a.cantidad);
                            banca_ -= a.cantidad;
                        }
                        else if (a.valor == "impar" && bola_ % 2 == 1) {
                            j.setDinero(j.getDinero() + a.cantidad);
                            banca_ -= a.cantidad;
                        }
                        else {
                            j.setDinero(j.getDinero() - a.cantidad);
                            banca_ += a.cantidad;
                        }
                    }

                    break;
                case 4: //High/Low bet

                    if (bola_ == 0) {
                        j.setDinero(j.getDinero() - a.cantidad);
                        banca_ += a.cantidad;
                    }
                    else {
                        if (a.valor == "alto" && bola_ >= 19) {
                            j.setDinero(j.getDinero() + a.cantidad);
                            banca_ -= a.cantidad;
                        }
                        else if (a.valor == "bajo" && bola_ <= 18) {
                            j.setDinero(j.getDinero() + a.cantidad);
                            banca_ -= a.cantidad;
                        }
                        else {
                            j.setDinero(j.getDinero() - a.cantidad);
                            banca_ += a.cantidad;
                        }
                    }

                    break;
            }
        }
    }
}

//Returns information about the roulette's current state
void Ruleta::getEstado(int& jugadores, int& dinero, int& lanzamientos, int& beneficio) const {
    jugadores = jugadores_.size();
    
    dinero = 0;
    for (Jugador j : jugadores_) {
        dinero += j.getDinero();
    }
    dinero += banca_;

    lanzamientos = lanzamientos_;

    beneficio = banca_ - 1000000; //Current amount - initial amount
}