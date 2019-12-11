#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <cstdlib>
#include <ctime>

#include "jugador.h"

#define VECTOR_SIZE 5

bool comp (Jugador a, Jugador b) {
    int dniA = std::stoi(a.getDNI().substr(0, 8));
    int dniB = std::stoi(b.getDNI().substr(0, 8));

    return dniA > dniB;
}

int main () {
    srand(time(NULL));

    std::vector<Jugador> v(VECTOR_SIZE);
    for (int i = 0; i < v.size(); i++) {
        Jugador aux((rand() % 100000000) + "X", "c" + i);
        v.push_back(aux);
    }

    std::sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++) {
        std::cout << "v[" << i << "]'s DNI = " << v[i].getDNI() << std::endl;
    }

    return 0;
}