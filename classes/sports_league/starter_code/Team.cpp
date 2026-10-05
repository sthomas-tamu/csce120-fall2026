#include "Team.h"

// TODO(@Student): Implement all data members here
//                 The first one is provided for you

// getter and setter for name_
std::string Team::name() const {
  return name_;
}

void Team::set_name(const std::string& s) {
  name_ = s;
}

