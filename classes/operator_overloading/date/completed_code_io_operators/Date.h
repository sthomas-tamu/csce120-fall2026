#ifndef DATE_H_
#define DATE_H_

#include <iostream>

class Date {
 private:
  unsigned int month_, day_, year_;

 public:
  Date() : month_{1}, day_{1}, year_{1876} {}  // year A&M founded :)
  Date(unsigned int m, unsigned int d, unsigned int y)
    : month_{m}, day_{d}, year_{y} {}
  ~Date() {}

  unsigned int month() const { return month_; }
  unsigned int day() const { return day_; }
  unsigned int year() const { return year_; }

  bool operator==(const Date& rhs) const;
  bool operator!=(const Date& rhs) const;

  bool operator<(const Date& rhs) const;
  bool operator<=(const Date& rhs) const;

  Date& operator++();    // prefix operator++ for ++date
  Date operator++(int);  // postfix operator++ for date++
};

// helper functions
unsigned int days_in_month(unsigned int month, unsigned int year);
bool is_leap_year(unsigned int year);

// i/o functions
std::istream& operator>>(std::istream& is, Date& date);
std::ostream& operator<<(std::ostream& os, const Date& date);

#endif  // DATE_H_
