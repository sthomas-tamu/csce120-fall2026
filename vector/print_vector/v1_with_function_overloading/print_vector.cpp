#include <iostream>
#include <vector>
#include <string>

void print_vector(const std::vector<int>& v) {
  std::cout << '[';
  bool first = true;
  for (int element : v) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << element;
    first = false;
  }
  std::cout << ']';
}

void print_vector(const std::vector<std::string>& v) {
  std::cout << '[';
  bool first = true;
  for (std::string element : v) {
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
