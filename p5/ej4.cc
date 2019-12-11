#include <iostream>
#include <vector>
#include <algorithm>

#define VECTOR_SIZE 5

bool descSort (int a, int b) { return a > b; }
bool ascSort  (int a, int b) { return b > a; }

int main () {
    std::vector<int> v(VECTOR_SIZE);
    for (int i = 0; i < v.size(); i++) {
        std::cout << "Introduzca v[" << i << "]: ";
        std::cin >> v[i];
    }

    int op;
    do {
        std::cout << "Como ordenar el vector? (0 ascendente, 1 descendente)" << std::endl;
        std::cin >> op;
        
        if (op != 0 && op != 1) {
            std::cout << "ERROR: Opcion no valida" << std::endl;
        }
    } while(op != 1 && op != 0);
    
    std::sort(v.begin(), v.end(), (op == 0 ? ascSort : descSort));

    for (int i = 0; i < v.size(); i++) {
        std::cout << "v[" << i << "] = " << v[i] << std::endl;
    }

    return 0;
}