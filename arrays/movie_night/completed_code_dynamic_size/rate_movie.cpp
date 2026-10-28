#include <iostream>
#include <sstream>

int main() {
  std::cout << "=== Movie Night Rating System ===\n";
  std::cout << "Rate our movie from 1-10\n\n";

  // Create ratings array
  int GROUP_SIZE = 0;
  int* ratings = nullptr;

  // Collect group size and ratings
  try {
    std::cout << "Enter the number of people in the group:\n";
    std::cin >> GROUP_SIZE;
    // check that the group size is greater than 0
    if (std::cin.fail() || GROUP_SIZE <= 0) {
      throw std::invalid_argument("Invalid group size. Groups must have at least 1 person.");
    }
    ratings = new int[GROUP_SIZE];

    std::cout << "Enter " << GROUP_SIZE << " ratings:\n";
    for (int i = 0; i < GROUP_SIZE; i++) {
      std::cout << "Person " << (i + 1) << ": ";
      std::cin >> ratings[i];
      // check that rating is an integer between 1 and 10
      if (std::cin.fail() || ratings[i] < 1 || ratings[i] > 10) {
        std::ostringstream message;
        message << "Invalid rating for person " << i + 1
          << ". Rating must be an integer between 1 and 10.";
        throw std::invalid_argument(message.str());
      }
    }
  }
  catch (std::invalid_argument& e) {
    std::cout << "ERROR: " << e.what() << " Exiting.\n";
    return -1;
  }

  // Calculate average
  double sum = 0;
  for (int i = 0; i < GROUP_SIZE; ++i)
    sum += ratings[i];
  double average = sum / GROUP_SIZE;

  // TODO(@Student): compute and print highest and lowest rating
  int high = ratings[0];
  int low = ratings[0];
  for (int i = 0; i < GROUP_SIZE; ++i) {
    if (ratings[i] > high)
      high = ratings[i];
    if (ratings[i] < low)
      low = ratings[i];
  }

  // Display results
  std::cout << "\n=== Results ===\n";
  std::cout << "Average rating: " << average << std::endl;
  std::cout << "Highest rating: " << high << std::endl;
  std::cout << "Lowest rating: " << low << std::endl;

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
