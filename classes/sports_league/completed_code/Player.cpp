#include "Player.h"

#include <sstream>

// getter and setter for name_
std::string Player::name() const {
  return name_;
}

void Player::set_name(const std::string& s) {
  name_ = s;
}

// getter and setter for jersey_number_
unsigned int Player::jersey_number() const {
  return jersey_number_;
}

void Player::set_jersey_number(unsigned int n) {
  jersey_number_ = n;
}

// getter and setter for position_
std::string Player::position() const {
  return position_;
}

void Player::set_position(const std::string& s) {
  position_ = s;
}

// print
std::string Player::print() const {
  std::ostringstream oss;
  oss << name_ << " (" << jersey_number_ << ", " << position_ << ")";
  return oss.str();
}
