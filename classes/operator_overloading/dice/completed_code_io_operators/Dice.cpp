#include <cstdlib>
#include "Dice.h"

Dice::Dice(unsigned int n) : sides_{n} {
  if (sides_ == 0)  // invalid number of sides, changing to 1
    sides_ = 1;

  roll();  // initial value_ is random roll
}

Dice::Dice(unsigned int n, unsigned int v) : sides_{n}, value_{v} {
  if (sides_ == 0)  // invalid number of sides, changing to 1
    sides_ = 1;

  if (value_ > sides_)  // invalid value, changing to max
    value_ = sides_;
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

std::istream& operator>>(std::istream& is, Dice& dice) {
  // note no Dice:: since outside class

  unsigned int sides, value;
  if (is >> sides >> value)  // only update dice if a valid read
    dice = Dice(sides, value);

  return is;
}

std::ostream& operator<<(std::ostream& os, const Dice& dice) {
  // note no Dice:: since outside class

  os << "[" << dice.sides() << " sides] " << dice.value();
  // must use getter functions since outside of class (no access)

  return os;
}
