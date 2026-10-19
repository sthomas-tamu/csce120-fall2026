#include <iostream>

#include "Range.h"

int main() {
  Range<int> rangeInt;
  std::cout << "adding 5, 2, -10, 4 to rangeInt\n";
  rangeInt.add(5);
  rangeInt.add(2);
  rangeInt.add(-10);
  rangeInt.add(4);
  std::cout << "rangeInt range is " << rangeInt.get_range() << "\n";
  std::cout << "\tmin is " << rangeInt.min() << "\n";
  std::cout << "\tmax is " << rangeInt.max() << "\n";

  Range<double> rangeDouble;
  std::cout << "adding 5.5, 2.2, -10.0, 4.4 to rangeDouble\n";
  rangeDouble.add(5.5);
  rangeDouble.add(2.2);
  rangeDouble.add(-10.0);
  rangeDouble.add(4.4);
  std::cout << "rangeDouble range is " << rangeDouble.get_range() << "\n";
  std::cout << "\tmin is " << rangeDouble.min() << "\n";
  std::cout << "\tmax is " << rangeDouble.max() << "\n";

  return 0;
}
