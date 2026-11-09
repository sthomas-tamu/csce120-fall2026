#include <iostream>

class Example {
  int a_;
  int* b_;

 public:
  Example(int a, int b) : a_{a}, b_{new int{b}} {}

  // TODO(@Student): Implement the rule of three

  std::ostream& print(std::ostream& os) const {
    os << a_ << ", ";
    if (b_ != nullptr)
      os << *b_;
    else
      os << " [null]";
    return os;
  }
};

std::ostream& operator<<(std::ostream& os, const Example& e) {
  return e.print(os);
}


int main() {
  Example x(1, 2);
  std::cout << "x: " << x << std::endl;

  Example y = x;
  std::cout << "y: " << y << std::endl;

  Example z(3, 4);
  std::cout << "z: " << z << std::endl;

  z = y;
  std::cout << "z: " << z << std::endl;

  return 0;
}
