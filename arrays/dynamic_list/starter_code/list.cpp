#include <algorithm>
#include <stdexcept>
#include "list.h"

List::List(size_t count, int value, size_t reserve) {
  size_ = count;
  capacity_ = count + reserve;
  array_ = new int[capacity_];
  for (size_t i = 0; i < size_; ++i)
    array_[i] = value;
}


List::~List() {
  if (array_ != nullptr)
    delete[] array_;
}


std::ostream& List::print(std::ostream& os) const {
  os << "(capacity = " << capacity_ << "):";
  if (size_ == 0) {
    os << " [empty]";
  } else {
    for (size_t i = 0; i < size_; ++i)
      os << " " << array_[i];
  }
  return os;
}


int List::pop() {
  if (size_ == 0)
    throw std::runtime_error("attempted to pop from an empty list");

  // get the last element
  int value = array_[size_ - 1];

  // update the size
  size_--;

  return value;
}


void List::push(int value) {
  // TODO(@Student): implement
}


void List::shrink_to_fit() {
  // TODO(@Student): implement
}


std::ostream& operator<<(std::ostream& os, const List& list) {
  return list.print(os);
}
