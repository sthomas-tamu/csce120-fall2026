#include <vector>
#include <iostream>

#include "Team.h"

int main() {
  // create some players
  std::cout << "Creating some players...\n";
  Player player1;
  player1.set_name("Maggie Aggie");
  player1.set_jersey_number(1);
  player1.set_position("goalie");
  std::cout << "Player 1: " << player1.print() << "\n";

  Player player2;
  player2.set_name("Miss Rev");
  player2.set_jersey_number(12);
  player2.set_position("striker");
  std::cout << "Player 2: " << player2.print() << "\n";
  std::cout << std::endl;

  // create a team and add players
  std::cout << "Creating a team...\n";
  Team aggies;
  aggies.set_name("Aggies");
  // TODO(@Student): Uncomment the rest once Team is implemented
  /*
  aggies.add_player(player1);
  aggies.add_player(player2);

  // print the team roster and record
  std::cout << "Team " << aggies.name() << ":\n";
  std::cout << aggies.print_roster();
  std::cout << "Record:\t" << aggies.print_record() << "\n";
  std::cout << std::endl;

  // update record to reflect some game outcomes
  std::cout << "Playing some games...\n";
  aggies.update_record('w');
  aggies.update_record('l');
  aggies.update_record('t');
  aggies.update_record('w');
  aggies.update_record('w');
  aggies.update_record('w');
  aggies.update_record('l');
  aggies.update_record('l');
  std::cout << "Record:\t" << aggies.print_record() << "\n";

  std::cout << "\nUpdating the roster...\n";

  // remove a player and print new roster
  std::cout << player1.print() << " graduated!\n";
  aggies.remove_player(player1);
  std::cout << aggies.print_roster() << "\n";

  // attempt to remove again
  std::cout << "Attempting removal again.\n";
  aggies.remove_player(player1);
  std::cout << aggies.print_roster() << "\n";

  // attempt to add again
  std::cout << "Attemping to add " << player2.print() << " again\n";
  aggies.add_player(player2);
  std::cout << aggies.print_roster() << "\n";
  */

  return 0;
}
