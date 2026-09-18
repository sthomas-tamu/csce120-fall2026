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


std::vector<double> solveLinear(double b, double c) {
  std::vector<double> roots;
  if (b != 0) {
    roots.push_back(-c / b);
  }
  return roots;
}


std::vector<double> solveQuadratic(double a, double b, double c) {
  /*
  compute discriminant
  if (discriminant is >= 0)
    compute roots using formula
  else
    complex root, no real roots
  */

  std::vector<double> roots;

  double discriminant = b*b - 4*a*c;
  std::cout << "Descriminant is " << discriminant << std::endl;

  if (discriminant >= 0) {  // real root
    roots.push_back((-b + sqrt(discriminant))/(2*a));

    // only have second root if discriminant is not 0
    if (discriminant != 0) {
      roots.push_back((-b - sqrt(discriminant))/(2*a));
    }
  }

  return roots;
}
