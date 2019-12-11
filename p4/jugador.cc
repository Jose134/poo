#include "jugador.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

//Reads a player's bets from his file (dni.txt)
void Jugador::setApuestas () {
    std::ifstream f(getDNI() + ".txt");
    
    //Checks if file exists
    if (f) {
        apuestas_.clear();

        Apuesta aux;
        std::string tipo, valor, cantidad;

        while (getline(f, tipo, ',')) {
            getline(f, valor, ',');
            getline(f, cantidad, '\n');

            //Sets auxiliar struct data
            aux.tipo = std::stoi(tipo);
            aux.valor = valor;
            aux.cantidad = std::stoi(cantidad);

            //Saves aux on the list
            apuestas_.push_back(aux);
        }
    }
    else {
        //File does not exist
        std::cerr << "ERROR: No se pudo abrir el archivo <" << (getDNI() + ".txt") << ">" << std::endl;
    }

    f.close();
}