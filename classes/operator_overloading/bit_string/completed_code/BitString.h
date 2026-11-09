#ifndef BIT_STRING_H_
#define BIT_STRING_H_

#include <string>
#include <iostream>

class BitString {
  std::vector<bool> bits_;

 public:
  BitString() : bits_{} {}
  BitString(const std::string& str) : bits_{} {
    // check that str is valid
    for (char c : str)
      if (c != '0' && c != '1') 
        return;

    for (char c : str)  // str is only 0s and 1s 
      bits_.push_back(c == '1');
  }

  size_t len() const { return bits_.size(); }

  bool get_bit(size_t index) const { return bits_.at(index); }

  void add_bit(bool bit) { bits_.push_back(bit); }

  bool operator==(const BitString& other) const { return bits_ == other.bits_; }

  friend std::ostream& operator<<(std::ostream& os, const BitString& b);
};

BitString operator^(const BitString& a, const BitString& b);

#endif  // BIT_STRING_H
