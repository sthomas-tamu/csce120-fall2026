#ifndef FAN_H_
#define FAN_H_

#include <iostream>
#include <string>

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

#endif  // FAN_H_
