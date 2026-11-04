#include <iostream>

class Thing {
  int data;

 public:
  Thing() : data{0} {
    std::cout << "\tcalled default constructor\n";
  }

  Thing(const Thing& other) : data{other.data} {
    std::cout << "\tcalled copy constructor\n";
  }

  Thing& operator=(const Thing& other) {
    std::cout << "\tcalled copy asignment operator\n";
    data = other.data;
    return *this;
  }
};

int main() {
  std::cout << "Thing one;\n";
  Thing one;

  std::cout << "Thing two(one);\n";
  Thing two(one);

  std::cout << "Thing three = two;\n";
  Thing three = two;

  std::cout << "three = one\n";
  three = one;

  return 0;
}
