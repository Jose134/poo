#include "persona.h"
#include <iostream>

int main () {
    Persona p("31874481T");

    std::cout << p.getDNI() << std::endl;

    return 0;
}