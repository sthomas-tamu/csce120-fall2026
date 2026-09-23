#include <iostream>
#include <string>

int main() {
  std::string term;

  do {
    std::cout << "Enter std::string to convert to an integer or 'x' to exit: ";
    std::cin >> term;

    if (term != "x") {
      size_t size = 0;
      try {
        int value = std::stoi(term, &size);
        std::cout << term << " times 2 is " << (value * 2) << std::endl;
      }
      // std::stoi will only throw invalid_argument and out_of_range
      catch (std::invalid_argument& e) {
        std::cout << "invalid argument - " << e.what() << std::endl;
      }
      catch (std::out_of_range& e) {
        std::cout << "out of range - " << e.what() << std::endl;
      }
    }
  } while (term != "x");

  return 0;
}
