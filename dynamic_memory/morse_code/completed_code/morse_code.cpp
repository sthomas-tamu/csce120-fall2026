#include "morse_code.h"

// constructor with initial symbols
MorseCode::MorseCode(const char* c, unsigned int l) : code_{nullptr}, length_{l} {
  if (length_ > 0) {
    code_ = new char[length_];
    for (unsigned int i = 0; i < length_; ++i)
      code_[i] = c[i];
  }
}

// copy constructor
MorseCode::MorseCode(const MorseCode& source) : code_{nullptr}, length_{source.length_} {
  if (length_ > 0) {
    code_ = new char[length_];
    for (unsigned int i = 0; i < length_; ++i)
      code_[i] = source.code_[i];
  }
}

// destructor
MorseCode::~MorseCode() {
  if (code_ != nullptr)
    delete[] code_;
}

// copy assignment operator
MorseCode& MorseCode::operator=(const MorseCode& source) {
  if (this == &source)
    return *this;

  if (code_ != nullptr)
    delete[] code_;

  length_ = source.length_;
  if (length_ > 0) {
    code_ = new char[length_];
    for (unsigned int i = 0; i < length_; ++i)
      code_[i] = source.code_[i];
  }

  return *this;
}

// concat operator
//   add a space only if both codes are not empty
MorseCode MorseCode::operator+(const MorseCode& other) const {
  unsigned int space = 0;
  if ((length_ > 0) && (other.length_ > 0))
    space = 1;

  unsigned int new_length = length_ + space + other.length_;
  char* new_code = new char[new_length];

  for (unsigned int i = 0; i < length_; ++i)
    new_code[i] = code_[i];

  if (space == 1)
    new_code[length_] = ' ';

  for (unsigned int i = 0; i < other.length_; ++i)
    new_code[length_ + space + i] = other.code_[i];

  MorseCode result(new_code, new_length);
  delete[] new_code;  // clean up temporary memory
  return result;
}

// print
std::ostream& MorseCode::print(std::ostream& os) const {
  for (unsigned int i = 0; i < length_; ++i)
    os << code_[i];
  return os;
}

std::ostream& operator<<(std::ostream& os, const MorseCode& mc) {
  return mc.print(os);
}
