#ifndef PAIR_H_
#define PAIR_H_

#include <iostream>

// TODO(@Student): generalize to be a pair of any type of data, not just int

class Pair {
 private:
  int first_;
  int second_;

 public:
  Pair(int a, int b) : first_(a), second_(b) {}

  int first()  const { return first_;  }
  int second() const { return second_; }

  bool operator<(const Pair& other) {
    // remember, class member functions have access to private data
    if (first_ == other.first_)
      return second_ < other.second_;
    else
       return first_ < other.first_;
  }
};

std::ostream& operator<<(std::ostream& os, const Pair& pair) {
  os << "(" << pair.first() << ", " << pair.second() << ")";
  return os;
}

#endif  // PAIR_H_
