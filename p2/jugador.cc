#include "jugador.h"
#include <string>
#include <fstream>
#include <iostream>

void Jugador::setApuestas () {
    std::ifstream f;
    f.open((getDNI() + ".txt"));

    if (f) {
        apuestas_.clear();

        Apuesta aux;
        char line[256];
        int count = 0;
        while (std::getline(f, line, ',')) {
            if      (count == 0) { aux.tipo = std::stoi(line); }
            else if (count == 1) { aux.valor = std::string(line); }
            else if (count == 2) { aux.cantidad = std::stoi(line); 

                apuestas_.push_back(aux);
                count = 0;
            }
            count++;
        }
    }
    else {
        std::cerr << "ERROR: No se pudo abrir el archivo <" << (getDNI() + ".txt") << ">" << std::endl;
    }

    f.close();
}