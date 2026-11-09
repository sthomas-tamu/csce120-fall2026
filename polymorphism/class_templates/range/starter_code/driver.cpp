#include <iostream>

#include "Range.h"

int main() {
  // TODO(@Class): update to be a Range of ints
  Range rangeInt;
  std::cout << "adding 5, 2, -10, 4 to rangeInt\n";
  rangeInt.add(5);
  rangeInt.add(2);
  rangeInt.add(-10);
  rangeInt.add(4);
  std::cout << "rangeInt range is " << rangeInt.get_range() << "\n";
  std::cout << "\tmin is " << rangeInt.min() << "\n";
  std::cout << "\tmax is " << rangeInt.max() << "\n";

  // TODO(@Class): add similar testing for a Range of doubles

  return 0;
}
