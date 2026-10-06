#include <iostream>

#include "Dice.h"

void test_dice(unsigned int num_sides, unsigned int num_rolls) {
  std::cout << "Creating a " << num_sides << "-sided dice" << std::endl;
  Dice d(num_sides);
  std::cout << "\t" << d.sides() << " sides, current value is "
    << d.value() << std::endl;

  std::cout << "Rolling the dice " << num_rolls << " times\n";
  for (unsigned int i = 0; i < num_rolls; ++i) {
    d.roll();
    std::cout << "\tcurrent value is " << d.value() << std::endl;
  }
  std::cout << std::endl;
}


int main() {
  test_dice(6, 10);

  test_dice(10, 5);

  test_dice(1, 5);

  return 0;
}
