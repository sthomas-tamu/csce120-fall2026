#ifndef DATE_H_
#define DATE_H_

class Date {
 private:
  unsigned int month_, day_, year_;

 public:
  Date(unsigned int m, unsigned int d, unsigned int y)
    : month_{m}, day_{d}, year_{y} {}
  ~Date() {}

  unsigned int month() const { return month_; }
  unsigned int day() const { return day_; }
  unsigned int year() const { return year_; }

  void print() const;

  bool operator==(const Date& rhs) const;
  bool operator!=(const Date& rhs) const;

  bool operator<(const Date& rhs) const;
  bool operator<=(const Date& rhs) const;
};

#endif  // DATE_H_
