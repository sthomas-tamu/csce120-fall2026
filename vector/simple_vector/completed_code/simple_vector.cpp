#include <iostream>
#include <string>
#include <vector>

void PrintVector(std::string label, const std::vector<int> v) {
  std::cout << "The " << label << " vector elements:" << std::endl;
  for (unsigned int i = 0; i < v.size(); ++i) {
    std::cout << label << "[" << i << "] = " << v.at(i) << std::endl;
  }
  std::cout << std::endl;
}


int SumVector(const std::vector<int> v) {
  int sum = 0;
  for (unsigned int i = 0; i < v.size(); ++i) {
    sum += v.at(i);
  }
  return sum;
}


int main() {
  // create an empty vector
  std::vector<int> empty_vector;
  PrintVector("empty", empty_vector);

  // initialize a vector with braces
  std::vector<int> odds = {1, 3, 5, 7, 9};
  PrintVector("odds", odds);

  // initialize a vector with 5 elements set to 0
  std::vector<int> evens(5, 0);

  // update all values
  for (unsigned int i = 0; i < evens.size(); ++i) {
    evens.at(i) = i*2;
  }

  // traverse and print values
  PrintVector("evens", evens);

  // access a single element
  std::cout << "front: " << evens.front() << std::endl;
  std::cout << "back: " << evens.back() << std::endl;
  std::cout << "at index 1: " << evens.at(1) << std::endl;
  // std::cout << "at index -1: " << evens.at(-1) << std::endl;

  // add contents to the vector
  evens.push_back(10);
  evens.push_back(12);
  PrintVector("updated evens", evens);
  // what is the new size?

  // sum the values
  std::cout << "The sum of the evens vector is "
    << SumVector(evens) << std::endl;
}
