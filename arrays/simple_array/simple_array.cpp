#include <iostream>
#include <array>

int main() {
  // declare array
  std::array<int, 5> primes {2, 3, 5, 7, 11};

  // print elements, iterating by const refererence
  std::cout << "The primes array:";
  for (const int& element : primes) {
    std::cout << " " << element;
  }
  std::cout << std::endl;

  std::cout << "printing again:";
  for (unsigned int i = 0; i < primes.size(); ++i) {
    std::cout << " " << primes.at(i);
  }
  std::cout << std::endl;

  // increment elements, iterate by reference
  for (int& element : primes) {
    element += 1;
  }
  std::cout << "The updated primes array:";
  for (const int& element : primes) {
    std::cout << " " << element;
  }
  std::cout << std::endl;

  // try to revert, iterate by value
  for (int& element : primes) {
    element -= 1;
  }
  std::cout << "The reverted primes array:";
  for (const int& element : primes) {
    std::cout << " " << element;
  }
  std::cout << std::endl;

  // create a zero-initialized array of the same size
  std::array<int, 5> primes_copy = {};
  std::cout << "The zero-initialized array:";
  for (const int& element : primes_copy) {
    std::cout << " " << element;
  }
  std::cout << std::endl;

  // copy the array
  primes_copy = primes;
  std::cout << "The updated primes_copy array:\t";
  for (const int& element : primes_copy) {
    std::cout << " " << element;
  }
  std::cout << std::endl;

  return 0;
}
