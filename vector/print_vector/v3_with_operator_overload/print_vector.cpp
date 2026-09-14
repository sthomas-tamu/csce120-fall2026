#include <iostream>
#include <vector>
#include <string>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  os << '[';
  bool first = true;
  for (T element : v) {
    if (!first) {
      os << ", ";
    }
    os << element;
    first = false;
  }
  os << ']';

  return os;
}

int main() {
  std::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<std::string> v2 = {"gig", "'em", "aggies"};

  std::cout << v1 << std::endl << v2 << std::endl;
}
