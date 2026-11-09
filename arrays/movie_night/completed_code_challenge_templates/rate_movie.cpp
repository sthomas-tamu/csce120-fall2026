#include <iostream>
#include <sstream>
#include <string>

// CHALLENGE: creating a simple struct to pair person's name and rating
#include "Pair.h" // reusing Pair class template idea from a prior week

int main() {
  std::cout << "=== Movie Night Rating System ===\n";
  std::cout << "Rate our movie from 1-10\n\n";

  // Create ratings array
  int GROUP_SIZE = 0;
  Pair<int, std::string>* ratings = nullptr;  // CHALLENGE: updated to be an array of pairs instead of int

  // Collect group size and ratings
  try {
    std::cout << "Enter the number of people in the group:\n";
    std::cin >> GROUP_SIZE;
    // check that the group size is greater than 0
    if (std::cin.fail() || GROUP_SIZE <= 0) {
      throw std::invalid_argument("Invalid group size. Groups must have at least 1 person.");
    }
    ratings = new Pair<int, std::string>[GROUP_SIZE];  // CHALLENGE: updated array type

    std::cout << "Enter " << GROUP_SIZE << " ratings:\n";
    for (int i = 0; i < GROUP_SIZE; i++) {
      std::cout << "Person " << (i + 1) << ":\n";

      // CHALLENGE: updated to read in person's name into Pair.second_; because a string, must clear any remaining input first
      std::string name;
      std::cout << "\tname: ";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::getline(std::cin, name);
      if (std::cin.fail()) {
        std::ostringstream message;
        message << "Invalid name for person " << i + 1;
        throw std::invalid_argument(message.str());
      }

      int rating;
      std::cout << "\trating: ";
      std::cin >> rating;  // CHALLENGE: updated to read into Pair.first_ (here and everywhere else)
      // check that rating is an integer between 1 and 10
      if (std::cin.fail() || rating < 1 || rating > 10) {
        std::ostringstream message;
        message << "Invalid rating for person " << i + 1
          << ". Rating must be an integer between 1 and 10.";
        throw std::invalid_argument(message.str());
      }

      ratings[i] = Pair<int, std::string>(rating, name);
    }
  }
  catch (std::invalid_argument& e) {
    std::cout << "ERROR: " << e.what() << " Exiting.\n";
    return -1;
  }

  // Calculate average
  double sum = 0;
  for (int i = 0; i < GROUP_SIZE; ++i)
    sum += ratings[i].first();
  double average = sum / GROUP_SIZE;

  // TODO(@Student): compute and print highest and lowest rating
  Pair<int, std::string> high = ratings[0];  // CHALLENGE: updated to Ratings struct instead of int
  Pair<int, std::string> low = ratings[0];
  for (int i = 0; i < GROUP_SIZE; ++i) {
    if (ratings[i].first() > high.first())
      high = ratings[i];
    if (ratings[i].first() < low.first())
      low = ratings[i];
  }

  // Display results
  std::cout << "\n=== Results ===\n";
  std::cout << "Average rating: " << average << std::endl;
  std::cout << "Highest rating: " << high.first()
    << ", given by \'" << high.second() << "\'\n";  // CHALLENGE: updated to print out name as well
  std::cout << "Lowest rating: " << low.first()
    << ", given by \'" << low.second() << "\'\n";

  // Recommendation
  if (average >= 7) {
    std::cout << "Consensus: Great movie!\n";
  } else if (average >= 5) {
    std::cout << "Consensus: It was okay.\n";
  } else {
    std::cout << "Consensus: Pick a different movie next time!\n";
  }

  // Release memory
  delete[] ratings;
  ratings = nullptr;  // not expressly needed but good habit

  return 0;
}
