#include <iostream>

int main() {
  double sum = 0;
  int counter = 0;

  std::cout << "Enter a series of integers. Last number is -1" << std::endl;
  int value = 0;
  std::cin >> value;
  if (std::cin.fail()) {
    std::cout << "ERROR, not a number, aborting." << std::endl;
    return -1;
  }
  // std::cout << "read in " << value << std::endl;

  while (value != -1) {
    sum += value;
    counter++;
    // std::cout << "sum is now " << sum << ", counter is now " << counter << std::endl;

    std::cin >> value;
    if (std::cin.fail()) {
      std::cout << "ERROR, not a number, aborting." << std::endl;
      return -1;
    }
    // std::cout << "read in " << value << std::endl;
  }

  // check if no numbers were entered
  if (counter == 0) {
    std::cout << "No numbers were entered, there is no average." << std::endl;
  } else {
    std::cout << "The average is " << sum / counter << std::endl;
  }

  return 0;
}
