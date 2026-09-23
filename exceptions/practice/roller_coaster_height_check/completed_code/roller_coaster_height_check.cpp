#include <iostream>
#include <string>

void check_height(int height, int minimum) {
  // TODO(@Student):
  //   If height is negative, throw an std::invalid_argument with the message
  //     "Heights can't be negative, you can't ride"
  //   If height is less than minimum, throw the string "Too short to ride!"

  if (height < 0) {
    throw std::invalid_argument("Heights can't be negative, you can't ride");
  }

  if (height < minimum) {
    throw std::string("Too short to ride!");
  }

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
  try {
    if (std::cin >> height) {
      check_height(height, height_required);
    } else {
      throw std::invalid_argument("Invalid input, you can't ride");
    }
  }
  catch (std::string& e) {
    std::cout << e
      << " You must be " << height_required << " inches tall." << std::endl;
  }
  catch (std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "Thank you for visiting!" << std::endl;

  return 0;
}
