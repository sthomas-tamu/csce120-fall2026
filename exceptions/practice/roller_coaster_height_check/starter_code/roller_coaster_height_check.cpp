#include <iostream>
#include <string>

void check_height(int height, int minimum) {
  // TODO(@Student):
  //   If height is negative, throw an std::invalid_argument with the message
  //     "Heights can't be negative, you can't ride"
  //   If height is less than minimum, throw the string "Too short to ride!"

  std::cout << "Enjoy the ride!" << std::endl;
}

int main() {
  int height_required = 48;  // must be at least 48 inches to ride
  int height = 0;

  std::cout << "Enter your height in inches: ";
  // TODO(@Student):
  //   Attempt to read in the height
  //   If successful, call check_height
  //   Otherwise throw an std::invalid_argument with the message
  //     "Invalid input, you can't ride"
  //   Catch any exceptions thrown. If someone is too short,
  //     also report the minimum height required.

  std::cout << "Thank you for visiting!" << std::endl;

  return 0;
}
