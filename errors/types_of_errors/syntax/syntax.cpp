#include <iostream>

// 4 errors

int main() {
  unsigned int age = 0; // unsignd int age = 0;
  std::cout << "Enter your age: ";
  std::cin >> age; // cin >> age;

  if (12 < age & age < 20) { // if (12 < age < 20) {
    std::cout << "You are a teenager." << std::endl; // std::cout >> "You are a teenager." >> std::endl;
  }

  return 0;
}
