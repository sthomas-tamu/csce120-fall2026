#include <iostream>
#include <string>

void greet() {
  std::cout << "Hello!\n";
}

void greet(std::string name) {
  std::cout << "Hello, " << name << "!\n";
}

void greet(std::string name, int times) {
  for (int i = 0; i < times; i++)
    std::cout << "Hello, " << name << "!\n";
}

int main() {
  std::cout << "Calling greet():\n";
  greet();

  std::cout << "\nCalling greet(\"Alice\"):\n";
  greet("Alice");

  std::cout << "\nCalling greet(\"Bob\", 3):\n";
  greet("Bob", 3);

  return 0;
}
