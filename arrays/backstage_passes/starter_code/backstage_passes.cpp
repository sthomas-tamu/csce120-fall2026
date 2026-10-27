#include <iostream>
#include <string>
#include <stdexcept>

class Fan {
  std::string name_;
  size_t guests_;

 public:
  Fan() : name_{""}, guests_{0} {}
  Fan(std::string name, size_t guests)
    : name_{name}, guests_{guests} {}

  std::string name() const { return name_; }
  size_t guests() const { return guests_; }
};

std::istream& operator>>(std::istream& is, Fan& fan) {
  std::string name;
  size_t guests;
  if (is >> name >> guests)
    fan = Fan(name, guests);
  return is;
}

std::ostream& operator<<(std::ostream& os, const Fan& fan) {
  os << fan.name() << "\t(bringing " << fan.guests() << " guests)";
  return os;
}


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
  // TODO(@Student): add the new fan in the first unoccupied place,
  //                 only add if there is enough room for them and their guests,
  //                 if unsuccessful, return false
  return false;
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
    // TODO(@Student): allocate a c-style array on the heap,
    //                 don't assume anyone is bringing a guest

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

  } catch (std::invalid_argument& e) {
    std::cout << "Error: " << e.what() << " Exiting.\n";
  }

  // Release backstage_pass list
  // TODO(@Student): clean up the heap (only if needed),

  return 0;
}
