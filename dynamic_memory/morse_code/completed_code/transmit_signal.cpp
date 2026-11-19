#include "morse_code.h"

int main() {
  // create morse code symbols S and O
  MorseCode S("...", 3);
  MorseCode O("---", 3);
  std::cout << "S: \"" << S << "\"\n";
  std::cout << "O: \"" << O << "\"\n";
  std::cout << std::endl;

  // create distress signal
  MorseCode help = S + O + S;
  std::cout << "help: \"" << help << "\"\n";
  std::cout << std::endl;

  // check that + words when one or both sides is empty
  MorseCode empty;
  std::cout << "Checking concatination with empty codes:\n";
  std::cout << "S + empty: \"" << (S + empty) << "\"\n";
  std::cout << "empty + S: \"" << (empty + S) << "\"\n";
  std::cout << "S + empty + O: \"" << (S + empty + O) << "\"\n";
  std::cout << "empty + empty: \"" << (empty + empty) << "\"\n";

  return 0;
}
