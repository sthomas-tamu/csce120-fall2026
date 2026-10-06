#include <cstdlib>
#include "Dice.h"

Dice::Dice(unsigned int n) : sides_{n} {
  if (n == 0)  // invalid number of sides, changing to 1
    n = 1;

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

// TODO(@Class): Implement == and !=
