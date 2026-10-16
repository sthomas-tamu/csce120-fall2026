#ifndef DICE_H_
#define DICE_H_

#include <iostream>

class Dice {
 private:
  unsigned int sides_;
  unsigned int value_;

 public:
  // Constructor
  Dice(unsigned int n);
  Dice(unsigned int n, unsigned int v);

  // Getter methods
  unsigned int sides() const;
  unsigned int value() const;

  void roll();

  // Comparison methods
  bool operator==(const Dice& rhs) const;
  bool operator!=(const Dice& rhs) const;
};

// i/o functions
std::istream& operator>>(std::istream& is, Dice& dice);
std::ostream& operator<<(std::ostream& os, const Dice& dice);

#endif  // DICE_H_
