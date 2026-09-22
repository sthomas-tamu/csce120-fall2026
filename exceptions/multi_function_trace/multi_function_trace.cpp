#include <iostream>
#include <string>

#define TRACE_START std::cout << padding << "-- start of " << __func__ << " --" << std::endl;
#define TRACE_END std::cout << padding << "-- end of " << __func__ << " --" << std::endl;

// pass along padding std::string so easier to see nested function calls
void A(bool cause_exception, const std::string& padding);
void B(bool cause_exception, const std::string& padding);
void C(bool cause_exception, const std::string& padding);
void D(bool cause_exception, const std::string& padding);

int main() {
  std::string padding = "";
  TRACE_START

  std::cout << "There are a series of nested function calls. A->B->C->D\n";
  std::cout << "Would you like the function D to throw an exception? y or n\n";
  char input;
  std::cin >> input;

  if (std::tolower(input) == 'y') {
    A(true, padding + "  ");
  } else if (std::tolower(input) == 'n') {
    A(false, padding + "  ");
  } else {
    std::cout << "invalid option, exiting." << std::endl;
  }

  TRACE_END
  return 0;
}


void A(bool cause_exception, const std::string& padding) {
  TRACE_START

  B(cause_exception, padding + "  ");

  TRACE_END
}


void B(bool cause_exception, const std::string& padding) {
  TRACE_START

  try {
    C(cause_exception, padding + "  ");
  } catch (const std::out_of_range& err) {
    std::cout << padding << "B: caught an out_of_range exception from C\n";
    std::cout << padding << "   what(): " << err.what() << std::endl;
  }

  TRACE_END
}


void C(bool cause_exception, const std::string& padding) {
  TRACE_START

  D(cause_exception, padding + "  ");

  TRACE_END
}


void D(bool cause_exception, const std::string& padding) {
  TRACE_START

  if (cause_exception) {
    std::cout << padding << "D is calling a function that throws an exception\n";
    std::string s = "hi";
    std::cout << s.at(3);
  } else {
    std::cout << padding << "D is doing nothing" << std::endl;
  }

  TRACE_END
}
