#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

double calculate(std::string line) {
  double first_number = 0, second_number = 0;
  char op = ' ';

  std::istringstream iss(line);

  // read in first_number
  if (!(iss >> first_number)) {
    std::string msg = "Unable to read the first number in '" + line + "'";
    throw std::invalid_argument(msg);
  }
  // read in operator
  if (!(iss >> op)) {
    std::string msg = "Unable to read the operator in '" + line + "'";
    throw std::invalid_argument(msg);
  }
  // read in second_number
  if (!(iss >> second_number)) {
    std::string msg = "Unable to read the second number in '" + line + "'";
    throw std::invalid_argument(msg);
  }
  // nothing should be left over after the expression
  std::string leftover;
  if (iss >> leftover) {
    std::string msg = "Unexpected extra input '" + leftover + "' in '" + line + "'";
    throw std::invalid_argument(msg);
  }

  // compute answer based on operator
  double result = 0;
  if (op == '+') {
    result = first_number + second_number;
  } else if (op == '-') {
    result = first_number - second_number;
  } else if (op == '*') {
    result = first_number * second_number;
  } else if (op == '/') {
    if (second_number == 0) {
      throw std::invalid_argument("Unable to divide by zero");
    }
    result = first_number / second_number;
  } else {
    std::string msg = "Unknown operator '";
    msg += op;
    msg += "' in '" + line + "'";
    throw std::invalid_argument(msg);
  }

  return result;
}

int main() {
  std::cout << "Enter the expression to calculate in one line: " << std::endl;
  std::string line;
  std::getline(std::cin, line);

  try {
    double result = calculate(line);
    std::cout << "result: " << result << std::endl;
  } catch (const std::invalid_argument& err) {
    std::cout << err.what() << std::endl;
  }

  return 0;
}
