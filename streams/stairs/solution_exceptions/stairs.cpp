#include <iostream>
#include <limits>

int main() {
  unsigned int no_lines = 0;

  // read in number of "stairs"
  do {
    try {
      std::cout << "Please provide a number of lines to print the stair-case pattern: ";
      std::cin >> no_lines;
      std::cout << "read: " << no_lines << std::endl;

      if (std::cin.fail()) {  // failed to read an unsigned int: reset cin, throw exception
        // reset cin bits so can read again
        std::cin.clear();
        // remove any bad data in the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw std::invalid_argument("unable to read an unsigned integer");
      }

      if ((no_lines == 0) || (no_lines > 80)) {  // input out of range, throw exception
        // don't need to reset cin since read was successful

        // throw exception
        throw std::out_of_range("must be a number greater than 0 and less than 80");
      }
    }
    catch (const std::exception& e) {
      std::cout << "Error: " << e.what() << ", try again." << std::endl;
      no_lines = 0;  // reset no_lines to attempt while loop again
    }
  } while (no_lines == 0);

  // print "stairs"
  for (unsigned int i = 1; i <= no_lines ; ++i) {
    for (unsigned int j = 1 ; j <= i ; ++j) {
      std::cout << '*';
    }
    std::cout << std::endl;
  }

  return 0;
}
