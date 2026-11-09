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
  // TODO(@Student): fix to work in all situations

  code_ = new char[length_];
  for (unsigned int i = 0; i < length_; ++i)
    code_[i] = source.code_[i];
}

// destructor
MorseCode::~MorseCode() {
  // TODO(@Student): fix to work in all situations

  delete[] code_;
}

// copy assignment operator
MorseCode& MorseCode::operator=(const MorseCode& source) {
  // TODO(@Student): fix to work in all situations

  if (this == &source)
    return *this;

  length_ = source.length_;
  code_ = source.code_;

  return *this;
}

// concat operator
//   add a space only if both codes are not empty
MorseCode MorseCode::operator+(const MorseCode& other) const {
  // TODO(@Student): implement
  return MorseCode();  // returns empty code for now
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
