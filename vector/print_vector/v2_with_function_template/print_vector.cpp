#include <iostream>
#include <vector>
#include <string>

template <typename T>
void print_vector(const std::vector<T>& v) {
  std::cout << '[';
  bool first = true;
  for (T element : v) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << element;
    first = false;
  }
  std::cout << ']';
}

int main() {
  std::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<std::string> v2 = {"gig", "'em", "aggies"};

  print_vector(v1);
  std::cout << std::endl;

  print_vector(v2);
  std::cout << std::endl;

  // std::cout << v1 << std::endl << v2 << std::endl;
}
