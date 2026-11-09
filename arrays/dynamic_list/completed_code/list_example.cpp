#include "list.h"

int main() {
  bool verbose = true;

  // Create a list with no elements but reserve space for 3
  List list(0, 0, 3);
  std::cout << "initial list: " << list << std::endl;

  // Add 10 elements, list will resize if needed
  for (int i = 0; i < 10; ++i) {
    list.push(i*2);
    if (verbose)
      std::cout << "added " << i*2 << ": " << list << std::endl;
  }
  std::cout << "final list: " << list << std::endl;

  // Remove an element
  int last_element = list.pop();
  std::cout << "popped last element: " << last_element << std::endl;
  std::cout << "updated list: " << list << std::endl;

  // Shrink list
  list.shrink_to_fit();
  std::cout << "shrunk list: " << list << std::endl;

  return 0;
}
