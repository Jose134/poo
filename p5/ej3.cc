#include <iostream>
#include <vector>
#include <algorithm>

#define VECTOR_SIZE 5

int main () {
    std::vector<int> v(VECTOR_SIZE);
    for (int i = 0; i < v.size(); i++) {
        std::cout << "Introduzca v[" << i << "]: ";
        std::cin >> v[i];
    }

    std::cout << "Sorting..." << std::endl;
    std::sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        std::cout << "v[" << i << "] = " << v[i] << std::endl;
    }

    return 0;
}