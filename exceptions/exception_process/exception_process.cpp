#include <iostream>

void f1();
void f2();
void f3();

int main() {
  std::cout << "\n-- begin main --\n";
  try {
    std::cout << "--- begin try --\n";
    f1();
    std::cout << "--- end try --\n";
  }
  catch (int err) {
    std::cout << "---- caught a " << err << "\n";
  }
  std::cout << "-- end main --\n";
}

void f1() {
  std::cout << "\n-- begin f1 --\n";
  try {
    std::cout << "--- begin try --\n";
    f2();
    std::cout << "--- end try --\n";
  }
  catch (int err) {
    std::cout << "---- caught a " << err << "\n";
  }
  std::cout << "--- throw 7\n";
  throw 7;
  std::cout << "-- end f1 --\n";
}

void f2() {
  std::cout << "\n-- begin f2 --\n";
  try {
    std::cout << "--- begin try --\n";
    f3();
    std::cout << "--- end try --\n";
  }
  catch (int err) {
    std::cout << "---- caught a " << err << "\n";
  }
  std::cout << "--- throw 6\n";
  throw 6;
  std::cout << "-- end f2 --\n";
}

void f3() {
  std::cout << "\n-- begin f3 --\n";
  throw 8;
  std::cout << "-- end f3 --\n";
}

