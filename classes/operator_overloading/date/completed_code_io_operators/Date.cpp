#include "Date.h"

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

Date& Date::operator++() {  // prefix version
  day_++;
  if (day_ > days_in_month(month_, year_)) {  // move to next month
    day_ = 1;
    month_++;

    if (month_ > 12) {  // move to next year
      month_ = 1;
      year_++;
    }
  }

  return *this;
}

Date Date::operator++(int) {  // postfix version
  // reuse the prefix version
  Date tmp(*this);
  operator++();
  return tmp;
}

unsigned int days_in_month(unsigned int month, unsigned int year) {
  // months have 31 days except for
  // February which has 28 or 29 depending on the year and
  // April/June/September/November which as 30

  switch (month) {
    case 2:   // February, check for leap year
      if (is_leap_year(year))
        return 29;
      else
        return 28;
    case 4:   // April
    case 6:   // June
    case 9:   // September
    case 11:  // November
      return 30;
    default:
      return 31;
  }
}

bool is_leap_year(unsigned int year) {
  // leap years must be divisible by 4 and
  // cannot be divisible by 100 unless also divisible by 400

  // checking divisible by 400 first since always a leap year
  if (year % 400 == 0)
    return true;

  // not divisible by 400, so checking 100
  if (year % 100 == 0)
    return false;

  // not divisible by 100, so only leap year if divisible by 4
  return year % 4 == 0;
}

std::istream& operator>>(std::istream& is, Date& date) {
  // expected format is year month day
  unsigned int year, month, day;
  bool valid = false;
  if (is >> year >> month >> day)  // able to read in 3 unsigned ints
    if (1 <= month && month <= 12)  // a valid month
      if (1 <= day && day <= days_in_month(month, year))  // a valid day
        valid = true;

  if (valid)
    date = Date(month, day, year);
  else
    is.setstate(std::ios::failbit);  // note a failed read

  return is;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
  os << date.day() << " ";
  switch (date.month()) {
    case 1:  os << "Jan "; break;
    case 2:  os << "Feb "; break;
    case 3:  os << "Mar "; break;
    case 4:  os << "Apr "; break;
    case 5:  os << "May "; break;
    case 6:  os << "Jun "; break;
    case 7:  os << "Jul "; break;
    case 8:  os << "Aug "; break;
    case 9:  os << "Sep "; break;
    case 10: os << "Oct "; break;
    case 11: os << "Nov "; break;
    case 12: os << "Dec "; break;
  }
  os << date.year();
  return os;
}
