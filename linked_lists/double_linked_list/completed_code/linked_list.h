#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>
#include <string>

struct Node {
  char letter_;
  Node* next_;
  Node* prev_;
  Node(char letter) : letter_{letter}, next_{nullptr}, prev_{nullptr} {}
};


class LinkedList {
  Node* head_;
  Node* tail_;

  Node* find(const char& value) const;

 public:
  // constructors & deconstructor
  LinkedList() : head_{nullptr}, tail_{nullptr} {}
  LinkedList(const std::string& other);  // copy std::string
  LinkedList(const char* other);  // copy c-string
  LinkedList(const LinkedList& other);
  ~LinkedList() { clear(); }
  LinkedList& operator=(const LinkedList& other);

  void clear();

  void print(std::ostream& os = std::cout) const;
  void print_reverse(std::ostream& os = std::cout) const;

  // setters and getters
  char peek_front() const { return head_->letter_; }
  char peek_back() const { return tail_->letter_; }

  void insert_front(const char& value);
  void insert_back(const char& value);

  void insert_after(const char& value_to_add, const char& value_to_find);
  void insert_before(const char& value_to_add, const char& value_to_find);

  void remove(const char& value);

  bool contains(const char& value) const { return find(value) != nullptr; }
};

std::ostream& operator<<(std::ostream& os, const LinkedList& ll);

#endif  // LINKED_LIST_H_
