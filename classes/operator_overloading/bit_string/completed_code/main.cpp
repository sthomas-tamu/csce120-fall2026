#include <iostream>

#include "BitString.h"

int main() {
  BitString x("01001");
  BitString y("011");
  BitString z("00101");

  std::cout << "x: " << x << std::endl;  
  std::cout << "y: " << y << std::endl;  
  std::cout << "z: " << z << std::endl;  

  if ((x ^ y) == z)
    std::cout << "x ^ y == z" << std::endl;
  else
    std::cout << "Error in BitString ^ implementation." << std::endl;

  return 0;
}
