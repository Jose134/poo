#include "dados.h"
#include <iostream>

void printMenu () {
  std::cout << "0. Exit" << std::endl;
  std::cout << "1. Roll" << std::endl;
  std::cout << "2. Get Dice 1" << std::endl;
  std::cout << "3. Get Dice 2" << std::endl;
  std::cout << "4. Set Dice 1" << std::endl;
  std::cout << "5. Set Dice 2" << std::endl;
  std::cout << "6. Get Sum" << std::endl;
  std::cout << "7. Get Sub" << std::endl;
}

int main () {
  Dados d;
  int option;

  do {
      printMenu();
      std::cin >> option;

      int a;
      switch (option) {
        case 1:
            d.lanzamiento();
            std::cout << "Dices rolled" << std::endl;
          break;
        case 2:
          std::cout << "Dice 1 = " << d.getDado1() << std::endl;
          break;
        case 3:
          std::cout << "Dice 2 = " << d.getDado2() << std::endl;
          break;
        case 4:
          std::cout << "Give number for dice 1: " << std::endl;
          std::cin >> a;
          if(d.setDado1(a)) {
            std::cout << "Dice 1 updated succesfully" << std::endl;
          }
          else {
            std::cout << "ERROR: Number not in range" << std::endl;
          }
          break;
        case 5:
          std::cout << "Give number for dice 2: " << std::endl;
          std::cin >> a;
          if(d.setDado2(a)) {
            std::cout << "Dice 2 updated succesfully" << std::endl;
          }
          else {
            std::cout << "ERROR: Number not in range" << std::endl;
          }
          break;
        case 6:
          std::cout << "Sum = " << d.getSuma() << std::endl;
          break;
      }
  } while(option != 0);

  return 0;
}
