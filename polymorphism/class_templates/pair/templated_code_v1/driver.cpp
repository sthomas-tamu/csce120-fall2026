#include "Pair.h"

#include <string>

int main() {
  /*
  // Pair with int
  Pair<int> p1(1, 2);
  Pair<int> p2(2, 1);
  Pair<int> p3(1, 1);
  */

  // Pair with string
  Pair<std::string> p1("howdy", "ags");
  Pair<std::string> p2("gigem", "aggies");
  Pair<std::string> p3("howdy", "yall");

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
