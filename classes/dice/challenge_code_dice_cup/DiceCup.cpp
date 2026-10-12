#include "DiceCup.h"

DiceCup::DiceCup(unsigned int num_dice, unsigned int num_sides)
  : dice_(num_dice, Dice(num_sides)) {
  roll();  // initial value_ is random roll
}

unsigned int DiceCup::num_dice() const {
  return dice_.size();
}

std::vector<unsigned int> DiceCup::values() const {
  std::vector<unsigned int> v;
  for (const Dice& d : dice_)
    v.push_back(d.value());
  return v;
}

unsigned int DiceCup::total() const {
  unsigned int total = 0;
  for (const Dice& d : dice_)
    total += d.value();
  return total;
}

void DiceCup::roll() {
  for (Dice& d : dice_)
    d.roll();
}
