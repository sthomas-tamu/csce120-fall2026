#include <iostream>
#include <string>

template <typename T>
class Container {
  // data members
  T data_;

 public:
  // constructors
  Container() : data_{} {}
  Container(const T& t) : data_{t} {}

  // getters
  const T& data() const { return data_; }
};

// overload << operator
template <typename T>
std::ostream& operator<<(std::ostream& os, const Container<T>& c) {
  os << "Container(" << c.data() << ")";
  return os;
}


int main() {
  Container<int> c_int {1};
  Container<char> c_char {'a'};
  Container<Container<std::string> > c_c_str = {{"whoop!"}};

  std::cout << "c_int = "   << c_int  << std::endl;
  std::cout << "c_char = "  << c_char << std::endl;
  std::cout << "c_c_str = " << c_c_str  << std::endl;

  return 0;
}
