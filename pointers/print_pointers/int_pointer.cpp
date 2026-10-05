#include "print_variable.h"

int main() {
  // declare two integers and initialize them
  std::cout << "declaring some integers:\n";
  std::cout << "  int i = 4;" << std::endl << "  int j = 5;" << std::endl;
  int i = 4;
  int j = 5;
  print_variable(std::cout, "i", i);
  print_variable(std::cout, "j", j);

  // declare an integer pointer and initialize to point to integer i
  std::cout << "\ndeclaring a pointer that points to i:" << std::endl;
  std::cout << "  int* k = &i;" << std::endl;
  int* k = &i;
  print_variable(std::cout, "i", i);
  print_variable(std::cout, "j", j);
  print_variable(std::cout, "k", k);

  // update the integer pointer to point to integer j
  std::cout << "\nupdating the pointer to point to j:" << std::endl;
  std::cout << "  k = &j;" << std::endl;
  k = &j;
  print_variable(std::cout, "i", i);
  print_variable(std::cout, "j", j);
  print_variable(std::cout, "k", k);

  // update j directly
  std::cout << "\nupdating j directly:" << std::endl;
  std::cout << "  j = 10;" << std::endl;
  j = 10;
  print_variable(std::cout, "i", i);
  print_variable(std::cout, "j", j);
  print_variable(std::cout, "k", k);

  // update the data that k points to
  std::cout << "\nupdating the integer's value that k points to through k:" << std::endl;
  std::cout << "  *k = 15;" << std::endl;
  *k = 15;
  print_variable(std::cout, "i", i);
  print_variable(std::cout, "j", j);
  print_variable(std::cout, "k", k);

  return 0;
}
