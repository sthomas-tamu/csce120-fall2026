#include "Pair.h"

int main() {
  /*
  // Pair with int
  Pair<int> p1(1, 2);
  Pair<int> p2(2, 1);
  Pair<int> p3(1, 1);
  */

  // Pair with int and string
  Pair<int, std::string> p1(1, "ags");
  Pair<int, std::string> p2(2, "white");
  Pair<int, std::string> p3(1, "aggies");

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
