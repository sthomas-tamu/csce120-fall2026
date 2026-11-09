#include <stdexcept>

#include "Fan.h"

size_t total_count(Fan* list, size_t capacity) {
  size_t total = 0;
  for (size_t i = 0; i < capacity; ++i)
    if (!list[i].name().empty())
      total += 1 + list[i].guests();  // count fan plus their guests
  return total;
}


void print_fans(std::ostream& os, Fan* list, size_t capacity) {
  bool empty = true;
  for (size_t i = 0; i < capacity; ++i)
    if (!list[i].name().empty()) {
      empty = false;
      os << list[i] << std::endl;
    }
  if (empty)
    os << "(Empty list)\n";
  os << "Total head count: " << total_count(list, capacity) << std::endl;
}


bool add_fan(Fan* list, size_t capacity, const Fan& fan_to_add) {
  // check if enough room
  size_t num_to_add = 1 + fan_to_add.guests();
  if (num_to_add > (capacity - total_count(list, capacity)))
    return false;

  // find where to add them
  size_t index = 0;
  while (index < (capacity-1) && !list[index].name().empty()) {
    index++;
  }
  list[index] = fan_to_add;
  return true;
}


bool remove_fan(Fan* list, size_t capacity, const std::string name) {
  // find fan
  size_t index = 0;
  while (index < capacity && list[index].name() != name) {
    index++;
  }
  if (index >= capacity)  // fan not in list
    return false;

  // clear fan
  list[index] = Fan();

  // move everyone after up 1 spot
  index++;  // advance to next spot
  while (index < capacity && !list[index].name().empty()) {
    list[index-1] = list[index];
    index++;
  }

  return true;
}


int main() {
  int venue_capacity = 0;
  Fan* backstage_passes = nullptr;

  try {
    // Get venue size
    std::cout << "What is the venue's capacity? ";
    if (!(std::cin >> venue_capacity) || venue_capacity <= 0) {
      throw std::invalid_argument("Invalid venue capacity. Must be > 0.");
    }
    // clearing rest of cin to prep for getline call
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Allocate backstage_pass list
    backstage_passes = new Fan[venue_capacity];  // max if no one brings a guest

    // Read in initial list, add only if room for them plus their guests
    bool done = false;
    while (!done) {
      std::cout << "Enter the fan's name to add or '.' if done: ";
      std::string fan_name = "";
      if (!std::getline(std::cin, fan_name))  // using getline for names with spaces
        throw std::invalid_argument("Unable to read fan's name.");

      if (fan_name != ".") {
        int fan_guests = 0;
        std::cout << "\tHow many guests? ";
        if (!(std::cin >> fan_guests) || (fan_guests < 0))
          throw std::invalid_argument("Invalid number of guests. Must be >= 0.");
        // clearing rest of cin to prep for getline call
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        Fan fan(fan_name, fan_guests);

        if (!add_fan(backstage_passes, venue_capacity, fan)) {
          std::cout << "Not enough room to add this fan and their guests."
            << " Already have " << total_count(backstage_passes, venue_capacity)
            << " out of " << venue_capacity << " on the list.\n";
        } else {
          size_t remaining_capacity = venue_capacity - total_count(backstage_passes, venue_capacity);
          std::cout << "Fan added. There is now room for " << remaining_capacity << " more.\n";
          if (remaining_capacity == 0) {
            std::cout << "\tVenue now completely full. Done adding fans.\n";
            done = true;
          }
        }
      } else {
        done = true;
      }
    }

    // Report backstage_pass list and remaining capacity
    std::cout << "Backstage Pass List:\n";
    print_fans(std::cout, backstage_passes, venue_capacity);
    std::cout << "Remaining spots: "
       << venue_capacity - total_count(backstage_passes, venue_capacity)
       << std::endl;

    // Remove the second person
    if (venue_capacity > 1) {
      std::cout << "\nRemoving the second fan\n";
      if (!remove_fan(backstage_passes, venue_capacity, backstage_passes[1].name()))
        std::cout << "\tFan not found.\n";
      print_fans(std::cout, backstage_passes, venue_capacity);
    }

    // Remove the first person
    std::cout << "\nRemoving the first fan\n";
    if (!remove_fan(backstage_passes, venue_capacity, backstage_passes[0].name()))
      std::cout << "\tFan not found.\n";
    print_fans(std::cout, backstage_passes, venue_capacity);

  } catch (std::invalid_argument& e) {
    std::cout << "Error: " << e.what() << " Exiting.\n";
  }

  // Release backstage_pass list
  if (backstage_passes != nullptr)
    delete[] backstage_passes;

  return 0;
}
