#include "BitString.h"

std::ostream& operator<<(std::ostream& os, const BitString& b) {
  for (size_t i = 0; i < b.len(); ++i) {
    os << b.get_bit(i);
  }
  return os;
}

BitString operator^(const BitString& a, const BitString& b) {
  BitString result;

  bool b_longer = b.len() > a.len();

  // get the minimum length
  size_t min_length = b.len();
  if (b_longer) 
    min_length = a.len();

  // compute xor up through minimum length
  for (size_t i = 0; i < min_length; ++i)
    result.add_bit(a.get_bit(i) != b.get_bit(i));

  // compute xor through the remainder
  if (b_longer) {
    for (size_t i = min_length; i < b.len(); ++i)
      result.add_bit(b.get_bit(i));
  } else {
    for (size_t i = min_length; i < a.len(); ++i)
      result.add_bit(a.get_bit(i));
  }

  return result;
}

