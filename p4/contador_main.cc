#include "contador.h"
#include <iostream>

int main () {
    Contador c(10, 0, 100);
    std::cout << c.get() << std::endl;

    c = c + 20;
    std::cout << c.get() << std::endl;

    c = 20 + c;
    std::cout << c.get() << std::endl;

    c = c + 100;
    std::cout << c.get() << std::endl;

    return 0;
}