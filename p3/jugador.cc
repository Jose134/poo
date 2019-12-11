#include "jugador.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>


void Jugador::setApuestas () {
   /*std::ifstream f;
    f.open((getDNI() + ".txt"));*/
    std::ifstream f(getDNI() + ".txt");
    
    if (f) {
        apuestas_.clear();

        Apuesta aux;
        std::string tipo, valor, cantidad;
        while (getline(f, tipo, ',')) {
            getline(f, valor, ',');
            getline(f, cantidad, '\n');

            aux.tipo = std::stoi(tipo);
            aux.valor = valor;
            aux.cantidad = std::stoi(cantidad);

            apuestas_.push_back(aux);
        }
    }
    else {
        std::cerr << "ERROR: No se pudo abrir el archivo <" << (getDNI() + ".txt") << ">" << std::endl;
    }

    f.close();
}