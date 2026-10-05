#include <iostream>
#include <string>
#include <ctime>

// return the middle of the string
std::string get_middle_third(std::string& str) {
  std::string return_string;

  size_t third = str.size() / 3;  // may be some rounding errors
  for (size_t i = third; i < (third * 2); ++i) {
    return_string += str.at(i);
    str.at(i) = '.';
  }

  return return_string;
}

int main() {
  srand(time(NULL));

  std::cout << "Enter a string: ";
  std::string s;
  std::getline(std::cin, s);

  std::cout << "middle third: " << get_middle_third(s) << std::endl;
  std::cout << "original string: " << s << std::endl;

  return 0;
}
