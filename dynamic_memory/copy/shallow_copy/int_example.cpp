#include <iostream>

int main() {
  int* a = new int{1};
  int* b = new int{2};
  b = a;
  *a = 3;

  std::cout << "*a: " << *a << std::endl;
  std::cout << "*b: " << *b << std::endl;

  delete a;
  delete b;
}
