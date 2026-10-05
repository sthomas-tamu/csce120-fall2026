#ifndef PRINT_VARIABLE_H_
#define PRINT_VARIABLE_H_

#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
void print_variable(std::ostream& os, const std::string& label, const T& x) {
  os << label << ":";
  os << "\taddress = " << &x;
  os << "\tvalue = " << x;

  // if T is a pointer, also print what it points to (deference it)
  // at compile time, we can check if T is a pointer type
  //   constexpr tells the compiler to check at compile time
  //   and only include the instructions inside the if statement if true
  if constexpr (std::is_pointer_v<T>) {
    os << "\tpoints to = " << *x;
  }
  os << std::endl;
}

#endif  // PRINT_VARIABLE_H_
