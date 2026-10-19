#include "Pair.h"

int main() {
  // Pair with int
  Pair p1(1, 2);
  Pair p2(2, 1);
  Pair p3(1, 1);

  // Print pairs
  std::cout << "p1: " << p1 << std::endl;
  std::cout << "p2: " << p2 << std::endl;
  std::cout << "p3: " << p3 << std::endl;
  std::cout << std::endl;

  // Compare pairs
  std::cout << "p1 < p2: " << (p1 < p2) << std::endl;
  std::cout << "p1 < p3: " << (p1 < p3) << std::endl;

  return 0;
}
