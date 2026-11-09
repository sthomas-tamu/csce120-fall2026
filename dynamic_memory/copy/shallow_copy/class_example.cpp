#include <iostream>

class A {
  int* a_ = nullptr;

 public:
  A(int a) : a_{new int{a}} {}

  void release() { delete a_; a_ = nullptr; }

  void print() const {
    std::cout << "a_: " << a_ << std::endl;
    if (a_ != nullptr)
      std::cout << "*a_: " << *a_ << std::endl;
  }
};

int main() {
  A x(1);
  A y(x);

  A z(2);
  z = x;

  x.release();

  x.print();
  y.print();
  z.print();
}

