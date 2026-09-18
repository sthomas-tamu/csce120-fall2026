#include <iostream>
#include "functions.h"

int main() {
  // prompt user for coefficients a, b, c
  std::cout << "Input coefficients a, b, and c for your equation: ";
  double a = 0, b = 0, c = 0;
  std::cin >> a >> b >> c;
  // should add error checking of inputs here

  // output equation ax^2 + bx + c = 0
  outputEquation(a, b, c);

  // solve for roots
  std::vector<double> roots;
  if (a == 0) {
    // solve linear version
    roots = solveLinear(b, c);

    if (roots.empty()) {
      std::cout << "Error! Not a valid equation (no solution or infinite solutions)" << std::endl;
    }

  } else {
    // solve quadratic version
    roots = solveQuadratic(a, b, c);

    if (roots.empty()) {
      std::cout << "No real roots" << std::endl;
    }
  }

  // output and check roots
  for (unsigned int i = 0; i < roots.size(); ++i) {
    std::cout << "Root " << i << ": " << roots.at(i) << std::endl;
    std::cout << "\tChecking root " << i << ": " << std::boolalpha << checkRoot(a, b, c, roots.at(i)) << std::endl;
  }

  return 0;
}
