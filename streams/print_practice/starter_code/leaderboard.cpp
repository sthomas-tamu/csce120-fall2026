#include <print>
#include <string>
#include <vector>

struct Player {
  std::string username;
  unsigned int score;
  unsigned int wins;
  unsigned int losses;
};

void print_leaderboard(const std::vector<Player>& players) {
  // Print each player's rank, name, score, and win rate
  //   Rank: right justified, 4 spaces wide
  //   Name: left justified, 18 spaces wide
  //   Score: right justified, 10 spaces wide
  //   Win %: right justified, 6 spaces wide, 1 decimal place,
  //          include % symbol

  // Header
  std::println("╔════════════════════════════════════════════╗");
  std::println("║ {:^42} ║", "BATTLE ARENA LEADERBOARD");
  std::println("╠════════════════════════════════════════════╣");

  // Column headers
  std::println("║ {:>4} {:<18} {:>10} {:>7} ║",
    "Rank", "Player", "Score", "Win %");
  std::println("╠════════════════════════════════════════════╣");

  // Players are sorted by rank
  unsigned int rank = 0;
  for (const Player& p : players) {
    rank++;

    // Calculate win rate
    double winRate = p.wins;
    winRate = 100 * winRate / (p.wins + p.losses);

    // TODO(@Student): Print the player's info,
    //                 format as described at top of function
  }

  // Footer
  std::println("╚════════════════════════════════════════════╝");
}

int main() {
  // create leaderboard, sorted by rank
  std::vector<Player> leaderboard = {
    {"xXDragonSlayerXx", 15250, 48, 12},
    {"ProGamer99", 14800, 45, 15},
    {"NoobMaster", 12340, 38, 22},
    {"CasualPlayer", 8500, 25, 35},
    {"JustHereForFun", 3200, 10, 50}
  };

  print_leaderboard(leaderboard);

  return 0;
}
