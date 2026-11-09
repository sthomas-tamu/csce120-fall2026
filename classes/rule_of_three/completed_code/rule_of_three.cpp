#include <iostream>

class Example {
  int a_;
  int* b_;

 public:
  Example(int a, int b) : a_{a}, b_{new int{b}} {}

  Example(const Example& other) : a_{other.a_}, b_{nullptr} {
    if (other.b_ != nullptr)
      b_ = new int{*(other.b_)};
  }

  ~Example() {
    if (b_ != nullptr)
      delete b_;
  }

  Example& operator=(const Example& other) {
    a_ = other.a_;

    if (b_ != nullptr) {
      delete b_;
      b_ = nullptr;
    }
    if (other.b_ != nullptr)
      b_ = new int{*(other.b_)};

    return *this;
  }

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
