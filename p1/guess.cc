#include <iostream>
#include <ctime>
#include <cstdlib>

int main () {
  srand(time(NULL));
  int number = rand() % 10 + 1;
  int inputNumber;

  do {
    std::cout << "Introduce your guess: " << std::endl;
    std::cin >> inputNumber;

    if (inputNumber > number) {
      std::cout << "Your guess is greater than the number" << std::endl;
    }
    else if (inputNumber < number) {
      std::cout << "Your guess is smaller than the number" << std::endl;
    }
    else {
      std::cout << "Your guess is correct!" << std::endl;
    }

  } while(inputNumber != number);

  return 0;
}
