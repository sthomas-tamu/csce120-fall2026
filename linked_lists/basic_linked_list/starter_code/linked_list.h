#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>

struct Node {
  int data_;
  Node* next_;

  Node(int data) : data_{data}, next_{nullptr} {}
};


class LinkedList {
  Node* head_;
  Node* tail_;

 public:
  LinkedList() : head_{nullptr}, tail_{nullptr} {}
  LinkedList(const LinkedList& other);
  ~LinkedList() { clear(); }
  LinkedList& operator=(const LinkedList& other);

  void clear();

  void print(std::ostream& os = std::cout) const;

  void insert_front(int value);
  void insert_back(int value);
  void insert_after(int value_to_insert, int value_to_find);

  void remove(int value);

  bool contains(int value) const;
};

std::ostream& operator<<(std::ostream&, const LinkedList&);

#endif  // LINKED_LIST_H_
