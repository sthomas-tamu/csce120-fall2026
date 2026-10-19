#ifndef RANGE_H_
#define RANGE_H_

template <typename T>
class Range {
 private:
  bool has_data_;
  T min_, max_;

 public:
  Range() : has_data_{false} {}
  Range(const Range& source)
    : has_data_{source.has_data_}, min_{source.min_}, max_{source.max_} {}

  bool empty() const { return !has_data_; }

  void add(const T& value) {
    if (!has_data_) {
      has_data_ = true;
      min_ = max_ = value;
    } else {
      if (value < min_)
        min_ = value;
      if (value > max_)
        max_ = value;
    }
  }

  T min() const {
    if (!has_data_)
      throw std::runtime_error("cannot get min, no data in Range");
    return min_;
  }

  T max() const {
    if (!has_data_)
      throw std::runtime_error("cannot get max, no data in Range");
    return max_;
  }

  T get_range() const {
    if (!has_data_)
      throw std::runtime_error("cannot get range, no data in Range");
    return abs(max_ - min_);
  }
};

#endif  // RANGE_H_
