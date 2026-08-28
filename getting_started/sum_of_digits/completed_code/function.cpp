#include "function.h"

#include <iostream>

int sum_of_digits(int value) {
  int sum = 0;

  while (value > 0) {
    sum += value % 10;
    std::cout << "sum is " << sum << std::endl;
    value /= 10;
    std::cout << "x is " << value << std::endl;
  }

  return sum;
}
