#include "Dice.h"

int main() {
  Dice d1(6), d2(6);  // create 2 dice, set to 6 sides for now

  std::cout << "Enter the initial state for the 2 dice\n";
  std::cout << " (first_dice_sides first_dice_value second_dice_sides second_dice_value): ";
  while (!(std::cin >> d1 >> d2)) {
    std::cout << "Error, invalid input. Try again.\n";
    std::cout << "Enter the initial state for the 2 dice\n";
    std::cout << " (first_dice_sides first_dice_value second_dice_sides second_dice_value): ";
  }

  std::cout << "\nCreated 2 dice:\n";
  std::cout << "\tDice 1: " << d1 << std::endl;
  std::cout << "\tDice 2: " << d2 << std::endl;

  // compare the dice
  std::cout << "\nd1 == d2: " << (d1 == d2) << std::endl;
  std::cout << "d1 != d2: " << (d1 != d2) << std::endl;

  // roll until they are not the same
  while (d1 == d2) {
    d1.roll();
    d2.roll();
    std::cout << "\nRolled 2 dice:\n";
    std::cout << "\tDice 1: " << d1 << std::endl;
    std::cout << "\tDice 2: " << d2 << std::endl;
    std::cout << "\nd1 == d2: " << (d1 == d2) << std::endl;
    std::cout << "d1 != d2: " << (d1 != d2) << std::endl;
  }

  return 0;
}
