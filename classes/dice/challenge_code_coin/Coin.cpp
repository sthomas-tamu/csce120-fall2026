#include "Coin.h"

std::string Coin::value() const {
  if (dice_.value() == 1)
    return "heads";
  else
    return "tails";
}

