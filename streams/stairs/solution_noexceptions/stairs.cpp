#include <iostream>
#include <limits>

int main() {
  unsigned int no_lines = 0;

  // read in number of "stairs"
  do {
    std::cout << "Please provide a number of lines to print the stair-case pattern: ";
    std::cin >> no_lines;
    std::cout << "read: " << no_lines << std::endl;

    if (std::cin.fail()) {  // failed to read an unsigned int: reset cin, print error message
      // reset cin bits so can read again
      std::cin.clear();
      // remove any bad data in the buffer
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      std::cout << "unable to read an unsigned integer" << std::endl;

    } else if ((no_lines == 0) || (no_lines > 80)) {  // input out of range, print error message
      // don't need to reset cin since read was successful

      std::cout << "must be a number reater than 0 and less than 80, try again.\n";
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
