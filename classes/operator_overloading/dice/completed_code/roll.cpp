#include <iostream>
#include <string>

#include "Dice.h"

void print_dice(const Dice d, const std::string& label) {
  std::cout << label << ": "
    << d.sides() << " sides, value = " << d.value() << std::endl;
}

int main() {
  Dice d1(6), d2(6);  // create 2 6-sided dice
  std::cout << "Created 2 dice:\n";
  print_dice(d1, "\tDice 1");
  print_dice(d2, "\tDice 2");

  // compare the dice
  std::cout << "\nd1 == d2: " << (d1 == d2) << std::endl;
  std::cout << "d1 != d2: " << (d1 != d2) << std::endl;

  // roll until they are not the same
  while (d1 == d2) {
    d1.roll();
    d2.roll();
    std::cout << "\nRolled 2 dice:\n";
    print_dice(d1, "\tDice 1");
    print_dice(d2, "\tDice 2");
    std::cout << "\nd1 == d2: " << (d1 == d2) << std::endl;
    std::cout << "d1 != d2: " << (d1 != d2) << std::endl;
  }

  return 0;
}
