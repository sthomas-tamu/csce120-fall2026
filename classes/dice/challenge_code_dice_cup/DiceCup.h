#ifndef DICE_CUP_H_
#define DICE_CUP_H_

#include <vector>

#include "Dice.h"

class DiceCup {
 private:
  std::vector<Dice> dice_;

 public:
  // Constructor
  DiceCup(unsigned int num_dice, unsigned int num_sides);

  // Getter methods
  unsigned int num_dice() const;
  std::vector<unsigned int> values() const;
  unsigned int total() const;

  void roll();
};

#endif  // DICE_CUP_H_
