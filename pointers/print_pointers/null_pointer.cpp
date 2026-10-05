#include "print_variable.h"

int main() {
  // declare an interger pointer but don't initialize
  std::cout << "using an int pointer without initializing it\n";
  std::cout << "  int* k;" << std::endl;
  int* k;
  print_variable(std::cout, "k", k);

  // initialize it to a new int
  std::cout << "\ncreating a new int and setting the int pointer to point to it\n";
  std::cout << "  int j = 10;" << std::endl << "  k = &j;" << std::endl;
  int j = 10;
  k = &j;
  print_variable(std::cout, "j", j);
  print_variable(std::cout, "k", k);

  // set it to the nullptr
  std::cout << "\nsetting the int pointer to be the nullptr and attempting to use it\n";
  std::cout << "  k = nullptr;" << std::endl;
  k = nullptr;
  print_variable(std::cout, "k", k);

std::cout << "done\n";

  return 0;
}
