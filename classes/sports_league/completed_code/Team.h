#ifndef TEAM_H_
#define TEAM_H_

#include <string>
#include <vector>

#include "Player.h"

class Team {
 public:
  // TODO(@Student): provide function prototypes for all member methods here
  //                 the first one is provided for you

  // getter and setter for name_
  std::string name() const;
  void set_name(const std::string&);

 private:
  // TODO(@Student): provide data members here, the first one is provided for you
  // data members
  std::string name_ = "";
};

#endif  // TEAM_H
