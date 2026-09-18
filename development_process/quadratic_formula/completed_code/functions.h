#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <vector>

// Function declarations
void outputEquation(double a, double b, double c);

bool checkRoot(double a, double b, double c, double root);

std::vector<double> solveLinear(double b, double c);

std::vector<double> solveQuadratic(double a, double b, double c);

#endif  // FUNCTIONS_H_
