#include <iostream>

class Data {
 public:
  int* pair_;
  bool flag_;

  Data() : pair_{new int[2]{7, 8}}, flag_{false} {}

  ~Data() {
    delete[] pair_;
  }

  Data& operator=(const Data& d) {
    if (this == &d)
      return *this;

    flag_ = d.flag_;

    delete[] pair_;
    pair_ = nullptr;
    if (d.pair_ != nullptr)
      pair_ = new int[2]{d.pair_[0], d.pair_[1]};

    return *this;
  }
};

int main() {
  Data d1;
  Data d2 = d1;
  d1.flag_ = true;
  d1.pair_[0] = 3;
  std::cout << d1.pair_[0] << d2.pair_[0];
  return 0;
}
