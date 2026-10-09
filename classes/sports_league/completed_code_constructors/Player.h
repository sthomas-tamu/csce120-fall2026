#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

class Player {
 public:
  // constructor
  Player(const std::string& name, unsigned int jersey_number, const std::string& position)
   : name_{name}, jersey_number_{jersey_number}, position_{position} {}

  // getter for name_
  std::string name() const;
  // setter removed, only allowing through constructor

  // getter and setter for jersey_number_
  unsigned int jersey_number() const;
  // setter removed, only allowing through constructor

  // getter and setter for position_
  std::string position() const;
  // setter removed, only allowing through constructor

  std::string print() const;

 private:
  // data members
  std::string name_;
  unsigned int jersey_number_;
  std::string position_;
};

#endif  // PLAYER_H
