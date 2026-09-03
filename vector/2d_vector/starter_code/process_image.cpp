#include <iostream>
#include <vector>

#include "image_functions.h"

void printMenu() {  // do not modify unless you add another option
  std::cout << "----------------------------------" << std::endl;
  std::cout << " 'G': Make grayscale image" << std::endl;
  std::cout << " 'S': Make sepia image" << std::endl;
  std::cout << " 'N': Make invert image" << std::endl;
  std::cout << " 'Q': Quit" << std::endl;
  std::cout << "----------------------------------" << std::endl;
  std::cout << std::endl << "Please enter your choice: ";
}


int main() {
  std::vector<std::vector<Pixel> > image;  // declare 2d vector of Pixels

  char menuChoice = ' ';  // selected menu option
  do {
    printMenu();
    std::cin >> menuChoice;
    switch (toupper(menuChoice)) {  // allows user to input upper or lower case
      case 'G':
      case 'S':
      case 'N':
        ProcessImage(menuChoice, image);
        break;
      case 'Q':  // does nothing but needed or default will execute
        break;
      default:
        std::cout << "\n'" << menuChoice << "' is not a valid option'\n\n";
    }
  } while (toupper(menuChoice) != 'Q');
}
