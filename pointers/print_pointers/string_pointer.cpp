#include <iostream>
#include <string>

void print_string(std::ostream& os, const std::string& s) {
  os << "My string is: " << s << std::endl;
  os << "The first character is " << s.at(0) << std::endl;
}

void print_string(std::ostream& os, const std::string* p) {
  os << "My string pointer is: " << p << std::endl;
  os << "The string it points to is: " << *p << std::endl;

  // one way to derefence the pointer and access a member function
  os << "The first character is " << (*p).at(0) << std::endl;

  // another way to dereference the pointer (usual way)
  os << "Another way to get the first character " << p->at(0) << std::endl;
  os << std::endl;
}


int main() {
  // declare a string
  std::string str = "Howdy!";
  print_string(std::cout, str);

  // declare a string pointer
  std::string* strPtr = &str;
  print_string(std::cout, strPtr);

  // modify the string through the pointer
  std::cout << "Updating the first character through the string pointer:\n"; 
  strPtr->at(0) = 'R';
  print_string(std::cout, str);
  print_string(std::cout, strPtr);
  
  // modify the string directly
  std::cout << "Updating the first character through the string directly:\n"; 
  str.at(0) = 'D';
  print_string(std::cout, str);
  print_string(std::cout, strPtr);

  return 0;
}
