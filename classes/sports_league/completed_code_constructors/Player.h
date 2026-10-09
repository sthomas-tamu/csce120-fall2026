#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

class Player {
 public:
  // constructor
  Player(const std::string& name, unsigned int jersey_number, const std::string& position)
   : name_{name}, jersey_number_{jersey_number}, position_{position} {}

  // getter and setter for name_
  std::string name() const;
  void set_name(const std::string&);

  // getter and setter for jersey_number_
  unsigned int jersey_number() const;
  void set_jersey_number(unsigned int);

  // getter and setter for position_
  std::string position() const;
  void set_position(const std::string&);

  std::string print() const;

 private:
  // data members
  std::string name_;
  unsigned int jersey_number_;
  std::string position_;
};

#endif  // PLAYER_H
