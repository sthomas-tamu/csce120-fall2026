// find the max of 3 numbers
#include <iostream>
#include <limits>

int main() {
  std::cout << "Enter 3 numbers." << std::endl;

  int greatest = std::numeric_limits<int>::lowest();

  for (int i = 0; i < 3; ++i) {
    int value = 0;
    std::cin >> value;
    if (std::cin.fail()) {
      std::cout << "Error, not an integer! Start over." << std::endl;
      return -1;
    }
    std::cout << "Read in " << value << std::endl;

    if (value > greatest) {
      greatest = value;
    }
  }

  std::cout << "found the greatest! " << greatest << std::endl;

  return 0;
}
