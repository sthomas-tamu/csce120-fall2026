#ifndef LIST_H_
#define LIST_H_

#include <iostream>

class List {
  int* array_ = nullptr;
  size_t capacity_ = 0;
  size_t size_ = 0;

 public:
  List() {}
  List(size_t count, int value = 0, size_t reserve = 0);
  ~List();

  size_t size()     const { return size_;     }
  size_t capacity() const { return capacity_; }

  std::ostream& print(std::ostream& os) const;

  int pop();
  void push(int value);
  void shrink_to_fit();
};

std::ostream& operator<<(std::ostream& os, const List& list);

#endif  // LIST_H_
