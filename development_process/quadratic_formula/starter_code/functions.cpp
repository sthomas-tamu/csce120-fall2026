#include "functions.h"

#include <iostream>
#include <cmath>  // provides common math functions like sqrt and fabs

void outputEquation(double a, double b, double c) {
  std::cout << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;
}


bool checkRoot(double a, double b, double c, double root) {
  double EPSILON = 0.000000001;  // error threshold

  double value = a*root*root + b*root + c;
  return (abs(value) < EPSILON);
}

