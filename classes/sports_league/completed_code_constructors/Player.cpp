#include "Player.h"

#include <sstream>

std::string Player::name() const {
  return name_;
}

unsigned int Player::jersey_number() const {
  return jersey_number_;
}

std::string Player::position() const {
  return position_;
}

// print
std::string Player::print() const {
  std::ostringstream oss;
  oss << name_ << " (" << jersey_number_ << ", " << position_ << ")";
  return oss.str();
}
