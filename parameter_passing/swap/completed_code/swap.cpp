#include <iostream>

void swap(int& a, int& b) {
  // TODO(@Student): implement swap,
  //   make sure change persists outside function
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  int x = 11;
  int y = 7;

  std::cout << "before swap: " << std::endl;
  std::cout << "x: " << x << std::endl;
  std::cout << "y: " << y << std::endl;

  swap(x, y);

  std::cout << "after swap: " << std::endl;
  std::cout << "x: " << x << std::endl;
  std::cout << "y: " << y << std::endl;

  return 0;
}
