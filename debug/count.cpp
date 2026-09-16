#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers;
  // fill vector with random numbers between 0 and 9
  for (unsigned int i = 0; i < 10; ++i) {
      numbers.push_back(rand() % 10);
  }

  // print out vector
  std::cout << "numbers =\t";
  for (int num : numbers) {
    std::cout << " " << num;
  }
  std::cout << std::endl;

  // ask for a number to search for
  std::cout << "Which number would you like to count in the list?" << std::endl;
  int x = 0;
  std::cin >> x;
  if (std::cin.fail()) {
    std::cout << "Invalid input, exiting." << std::endl;
    return -1;
  }

  // count how many times x is in the vector
  int count = 0;
  for (int num : numbers) {
    if ((num = x)) {
      count++;
    }
  }
  std::cout << "There are " << count << " instances of " << x
    << " in the list\n.";

  return 0;
}
