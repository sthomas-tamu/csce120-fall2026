#include <iostream>
#include <string>

struct Preference {
  std::string name = "";
  bool prefers_morning = false;
};

void PrintPreference(const Preference p) {
  std::cout << p.name << " prefers ";
  if (p.prefers_morning) {
    std::cout << "morning" << std::endl;
  } else {
    std::cout << "evening" << std::endl;
  }
}

int main() {
  Preference p1 = {"Early Bird", true};
  Preference p2 = {"Night Owl", false};

  PrintPreference(p1);
  PrintPreference(p2);

  return 0;
}
