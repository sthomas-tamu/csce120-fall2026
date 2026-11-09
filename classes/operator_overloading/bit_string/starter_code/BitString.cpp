#include "BitString.h"

std::ostream& operator<<(std::ostream& os, const BitString& b) {
  for (size_t i = 0; i < b.len(); ++i) {
    os << b.get_bit(i);
  }
  return os;
}

BitString operator^(const BitString& a, const BitString& b) {
  BitString result;

  // TODO(@Student): implement

  return result;
}

