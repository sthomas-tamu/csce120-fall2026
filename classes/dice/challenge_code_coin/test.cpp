#include <iostream>

#include "Dice.h"
#include "Coin.h"

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

void test_coin(unsigned int num_flips) {
  std::cout << "Creating a coin\n";
  Coin c;
  std::cout << "\tcurrent value is " << c.value() << std::endl;

  std::cout << "Flipping the coin " << num_flips << " times\n";
  for (unsigned int i = 0; i < num_flips; ++i) {
    c.flip();
    std::cout << "\tcurrent value is " << c.value() << std::endl;
  }
  std::cout << std::endl;
}


int main() {
  test_dice(6, 10);

  test_dice(10, 5);

  test_dice(1, 5);

  test_coin(4);

  return 0;
}
