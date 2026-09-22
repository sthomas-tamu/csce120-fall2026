#include <iostream>
#include <string>

void validate_password(const std::string& password) {
  // TODO(@Student) Check password requirements.
  //   Throw string with appropriate error message if not.
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
