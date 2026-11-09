#include <iostream>

class A {
  int* a_ = nullptr;

 public:
  A(int a) : a_{new int{a}} {}

  // rule of 3: destructor, copy constructor, copy assignment
  A(const A& other) : a_{nullptr} {
    if (other.a_ != nullptr)
      a_ = new int{*(other.a_)};
  }

  ~A() {
    if (a_ != nullptr)
      delete a_;
  }

  A& operator=(const A& other) {
    // releases any existing memory first, then creates new memory if needed
    // doesn't consider reusing memory, always safe
    if (a_ != nullptr) {
      delete a_;
      a_ = nullptr;
    }

    if (other.a_ != nullptr)
      a_ = new int{*(other.a_)};

    return *this;
  }

  /*
  // another approach that reuses existing memory if can
  // more efficient but more complicated
  A& operator=(const A& other) {
    if (other.a_ == nullptr) {
      if (a_ != nullptr)
        delete a_;
      return *this;
    }

    // know that other.a_ not null
    if (a_ != nullptr)
      *a_ = *(other.a_);
    else
      a_ = new int{*(other.a_)};

    return *this;
  }
  */

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

