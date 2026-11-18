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
  bool empty() const { return head_ == nullptr; }

  void print(std::ostream& os = std::cout) const;

  void insert_front(int value);
  void insert_back(int value);
  void insert_after(int value_to_insert, int value_to_find);

  void remove(int value);  // removes first occurance of value; example of traversal with structure modification 
  int pop_front();  // removes first item; example of structure modification
  int pop_back();  // removes last item; example of structure modicfication
  void remove_duplicates();  // removes all duplicates; example of traversal with structure modification and using existing member functions

  bool contains(int value) const;  // returns true if list contains value; example of traversal with computation
  unsigned int count(int value) const;  // returns number of times value appears; example of traversal with computation

  // other examples
  void multiply(int value);  // multiplies every item by value; example of traversal with data modification
  void get_evens(LinkedList& new_list) const;  // creates a new list of evens; example of traversal with creation
};

std::ostream& operator<<(std::ostream&, const LinkedList&);

#endif  // LINKED_LIST_H_
