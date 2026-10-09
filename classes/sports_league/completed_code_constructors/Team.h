#ifndef TEAM_H_
#define TEAM_H_

#include <string>
#include <vector>

#include "Player.h"

class Team {
 public:
  // constructor
  Team(const std::string& name)
    : name_{name}, num_wins_{0}, num_losses_{0}, num_ties_{0} {}

  Team(const std::string& name, const std::vector<Player>& players)
    : name_{name}, players_{players}, num_wins_{0}, num_losses_{0}, num_ties_{0} {}

  // getter and setter for name_
  std::string name() const;
  void set_name(const std::string&);

  // update players_
  void add_player(const Player&);
  void remove_player(const Player&);

  // update record_
  void update_record(char);

  // print functions
  std::string print_roster() const;
  std::string print_record() const;

 private:
  // data members
  std::string name_;
  std::vector<Player> players_;
  unsigned int num_wins_;
  unsigned int num_losses_;
  unsigned int num_ties_;
};

#endif  // TEAM_H
