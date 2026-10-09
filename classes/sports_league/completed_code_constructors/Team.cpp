#include "Team.h"

#include <sstream>
#include <iostream>

// getter and setter for name_
std::string Team::name() const {
  return name_;
}

void Team::set_name(const std::string& s) {
  name_ = s;
}

// update players_
void Team::add_player(const Player& new_player) {
  // only add if player not already in the list
  for (const Player& p : players_) {
    if (p.name() == new_player.name()) {
      std::cout << "Warning, " << new_player.print()
        << " not added to team, already in roster.\n";
      return;
    }
  }
  players_.push_back(new_player);
}

void Team::remove_player(const Player& remove_player) {
  // looking for player to remove
  // could use erase() if Player supported the == operator...
  for (std::vector<Player>::const_iterator P = players_.begin(); P != players_.end(); ++P) {
    if (P->name() == remove_player.name()) {
      players_.erase(P);
      return;
    }
  }
  std::cout << "Warning, attempted to remove " << remove_player.print()
    << ", but not found in roster.\n";
}

// update record_
void Team::update_record(char outcome) {
  switch (std::tolower(outcome)) {
    case 'w': num_wins_++;   break;
    case 'l': num_losses_++; break;
    case 't': num_ties_++;   break;
    default:
      std::ostringstream msg;
      msg << "Invalid game outcome '" << outcome << "', must be w, l, or t.";
      throw std::invalid_argument(msg.str());
  }
}

// print functions
std::string Team::print_roster() const {
  std::ostringstream oss;
  oss << "Roster:";
  if (players_.empty()) {
    oss << " empty\n";
  } else {
    for (const Player& p : players_) {
      oss << "\t" << p.print() << "\n";
    }
  }
  return oss.str();
}

std::string Team::print_record() const {
  std::ostringstream oss;
  oss << "Wins: " << num_wins_
    << "\tLosses: " << num_losses_
    << "\tTies: " << num_ties_;
  return oss.str();
}
