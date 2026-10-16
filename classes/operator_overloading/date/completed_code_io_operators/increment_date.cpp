#include <iostream>

#include "Date.h"

int main() {
  Date date;
  std::cout << "Enter a date (year month day): ";
  while (std::cin >> date) {
    std::cout << "\tRead date:\t" << date << std::endl;

    ++date;
    std::cout << "\tNext date:\t" << date << std::endl;

    date++;
    std::cout << "\tAfter that:\t" << date << std::endl;

    std::cout << "\nEnter a date (year month day): ";
  }

  std::cout << "Invalid date, all done.\n";
  return 0;
}
