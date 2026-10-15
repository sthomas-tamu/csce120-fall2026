#include "Date.h"

#include <iostream>

void Date::print() const {
  std::cout << month_ << "/" << day_ << "/" << year_;
}

bool Date::operator==(const Date& rhs) const {
  return ((year_ == rhs.year_) &&
          (month_ == rhs.month_) &&
          (day_ == rhs.day_));
}

bool Date::operator!=(const Date& rhs) const {
  // can implement using == operator already defined
  return !(*this == rhs);

  // or can implement explicitly
  /*
  return ((year_ != rhs.year_) ||
          (month_ != rhs.month_) ||
          (day_ != rhs.day_));
  */
}

bool Date::operator<(const Date& rhs) const {
  // first compare the years
  if (year_ < rhs.year_) {
    return true;
  }
  if (year_ > rhs.year_) {
    return false;
  }

  // years are the same, next compare the months
  if (month_ < rhs.month_) {
    return true;
  }
  if (month_ > rhs.month_) {
    return false;
  }

  // year_s and month_s are the same, now compare the day_s
  // can simply use the < operator on days, nothing else to compare after it
  return (day_ < rhs.day_);
}

bool Date::operator<=(const Date& rhs) const {
  return (*this < rhs) || (*this == rhs);
}
