#include <iostream>
#include <string>

void validate_password(const std::string& password) {
  if (password.length() < 8) {
    throw std::string("Password is too short. It must be at least 8 characters long.");
  }

  if (password.length() > 20) {
    throw std::string("Password is too long. It must be at most 20 characters long.");
  }

  int num_digits = 0;
  int num_upper = 0;
  int num_lower = 0;
  for (const char c : password) {
    if (std::isdigit(c)) {
      num_digits++;
      continue;
    }
    if (std::isupper(c)) {
      num_upper++;
      continue;
    }
    if (std::islower(c)) {
      num_lower++;
    }
  }

  if (num_digits < 2) {
    throw std::string("Password must contain at least 2 digits.");
  }

  if (num_upper == 0 || num_lower == 0) {
    throw std::string("Password must contain upper and lower case letters.");
  }
}

int main() {
  std::string new_password = "";
  std::cout << "Enter a new password. It must be between 8 and characters long, "
    << "contain upper and lower case letters, and have at least 2 numbers.\n";

  std::cin >> new_password;
  try {
    validate_password(new_password);
    std::cout << "Your password has been updated." << std::endl;
  }
  catch (std::string& e) {
    std::cout << "Error, your new password \"" << new_password << "\" is not valid:\n";
    std::cout << "  " << e << std::endl;
    std::cout << "Password not updated." << std::endl;
  }

  return 0;
}
