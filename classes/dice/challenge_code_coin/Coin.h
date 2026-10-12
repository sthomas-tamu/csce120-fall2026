#ifndef COIN_H_
#define COIN_H_

#include <string>

#include "Dice.h"

class Coin {
 private:
  Dice dice_;

 public:
  // Constructor
  Coin() : dice_{2} {}

  // Getter methods
  std::string value() const;

  void flip() {
    dice_.roll();
  }
};

#endif  // COIN_H_
