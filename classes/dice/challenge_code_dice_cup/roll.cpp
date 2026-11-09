#include <iostream>

#include "DiceCup.h"

void test_dice_cup(unsigned int num_dice, unsigned int num_sides,
   unsigned int num_rolls) {
  std::cout << "Creating a dice cup with " << num_dice << " "
    << num_sides << "-sided dice" << std::endl;
  DiceCup dc(num_dice, num_sides);
  std::vector<unsigned int> values = dc.values();
  std::cout << "\t" << dc.num_dice() << " dice, current values are { ";
  for (unsigned int value : values)
    std::cout << value << " ";
  std::cout << "}, total is " << dc.total() << std::endl;

  std::cout << "Rolling the dice cup " << num_rolls << " times\n";
  for (unsigned int i = 0; i < num_rolls; ++i) {
    dc.roll();
    values = dc.values();
    std::cout << "\tcurrent values are { ";
    for (unsigned int value : values)
      std::cout << value << " ";
    std::cout << "}, total is " << dc.total() << std::endl;
  }
  std::cout << std::endl;
}


int main() {
  test_dice_cup(2, 6, 10);

  test_dice_cup(3, 10, 5);

  test_dice_cup(1, 1, 5);

  return 0;
}
