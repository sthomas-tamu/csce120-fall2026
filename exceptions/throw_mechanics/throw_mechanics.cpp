#include <iostream>
#include <string>
#include <stdexcept>

void throw_an_int() {
  std::cout << "-- begin throw_an_int --\n";
  throw 7;
  std::cout << "-- end throw_an_int --\n";
}

void throw_a_std_string() {
  std::cout << "-- begin throw_a_std_string --\n";
  throw std::string("ouch!");
  std::cout << "-- end throw_a_std_string --\n";
}

void throw_a_std_exception() {
  std::cout << "-- begin throw_a_std_exception --\n";
  throw std::invalid_argument("no no no, not in my house.");
  std::cout << "-- end throw_a_std_exception --\n";
}

struct PaperAirplane {
  std::string type = "dart";  // the classic
};

void throw_a_paper_airplane() {
  std::cout << "-- begin throw_a_paper_airplane --\n";
  throw PaperAirplane();
  std::cout << "-- end throw_a_paper_airplane --\n";
}

void f2() {
  std::cout << "-- begin f2 --\n";
  throw std::runtime_error("boo!");
  std::cout << "-- end f2 --\n";
}

void f1() {
  std::cout << "-- begin f1 --\n";
  f2();
  std::cout << "-- end f1 --\n";
}

int main() {
  std::cout << "What would you like to throw?\n";
  std::cout << "(1) int\n";
  std::cout << "(2) std::string\n";
  std::cout << "(3) std::invalid_argument\n";
  std::cout << "(4) PaperAirplane\n";
  std::cout << "(5) from the depths (nested function call)\n";
  std::cout << "> ";

  int number;
  if (std::cin >> number) {
    switch (number) {
      case 1:
        throw_an_int();
      case 2:
        throw_a_std_string();
      case 3:
        throw_a_std_exception();
      case 4:
        throw_a_paper_airplane();
      case 5:
        f1();
      default:
        throw std::out_of_range("I'm sorry, Dave. I'm afraid I can't do that.");
    }
  } else {
    std::cout << "Not a valid choice, do over.\n";
  }

  return 0;
}
