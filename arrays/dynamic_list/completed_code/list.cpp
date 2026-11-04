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
  if (size_ == capacity_) {  // full, increase capacity
    // compute new capacity
    size_t new_capacity = growth_rate_ * size_;
    if (new_capacity < (size_ + 1))
      new_capacity = size_ + 1;

    resize(new_capacity);
  }

  // insert new element and update size
  array_[size_] = value;
  size_++;
}


void List::shrink_to_fit() {
  if (size_ != capacity_)
    resize(size_);
}


void List::resize(size_t new_capacity) {
  // create new array
  int* new_array = new int[new_capacity];

  // copy over elements
  for (size_t i = 0; i < std::min(size_, new_capacity); ++i)
    new_array[i] = array_[i];

  // release old memory and update to new array
  delete[] array_;
  array_ = new_array;

  // update capacity
  capacity_ = new_capacity;
}

std::ostream& operator<<(std::ostream& os, const List& list) {
  return list.print(os);
}
