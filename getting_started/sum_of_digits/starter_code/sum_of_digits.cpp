#include <iostream>

#include "function.h"

int main() {
  std::cout << "Enter an integer" << std::endl;
  int x = 0;
  std::cin >> x;
  if (std::cin.fail()) {
    std::cout << "Error, failed to read in an integer, aborting." << std::endl;
    return -1;
  }
  std::cout << "read in " << x << std::endl;

  int result = sum_of_digits(x);
  std::cout << "the sum of digits is " << result << std::endl;

  return 0;
}
