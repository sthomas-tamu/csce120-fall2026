#include <cstdlib>
#include "Dice.h"

Dice::Dice(unsigned int n) : sides_{n} {
  if (sides_ == 0)  // invalid number of sides, changing to 1
    sides_ = 1;

  roll();  // initial value_ is random roll
}

unsigned int Dice::sides() const {
  return sides_;
}

unsigned int Dice::value() const {
  return value_;
}

void Dice::roll() {
  value_ = 1 +  (rand() % sides_);
}


bool Dice::operator==(const Dice& rhs) const {
  return value_ == rhs.value_;  // class member functions have access,
                                // even though proviate

  // another way: (explicitly referring to this)
  // return this->value_ == rhs.value_;
}

bool Dice::operator!=(const Dice& rhs) const {
  return value_ != rhs.value_;

  // another way: (reuse the == implementation)
  // return !(*this == rhs);
}
