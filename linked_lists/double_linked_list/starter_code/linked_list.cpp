#include "linked_list.h"

LinkedList::LinkedList(const std::string& other)
  : head_{nullptr}, tail_{nullptr} {
  for (size_t i = 0; i < other.size(); ++i)
    insert_back(other.at(i));
}


LinkedList::LinkedList(const char* other)
  : head_{nullptr}, tail_{nullptr} {
  size_t index = 0;
  while (other[index] != '\0') {
    insert_back(other[index]);
    index++;
  }
}


LinkedList::LinkedList(const LinkedList& other)
  : head_{nullptr}, tail_{nullptr} {
  const Node* cur = other.head_;
  while (cur != nullptr) {
    insert_back(cur->letter_);
    cur = cur->next_;
  }
}


void LinkedList::clear() {
  Node* cur = tail_;
  while (cur != head_) {
    cur = cur->prev_;
    delete cur->next_;
  }
  if (head_ != nullptr)
    delete head_;
}


LinkedList& LinkedList::operator=(const LinkedList& other) {
  if (this == &other)
    return *this;

  clear();

  const Node* cur = other.head_;
  while (cur != nullptr) {
    insert_back(cur->letter_);
    cur = cur->next_;
  }
  return *this;
}


Node* LinkedList::find(const char& value) const {
  // TODO(@Student): Task #1
  return nullptr;
}


void LinkedList::print(std::ostream& os) const {
  Node* cur = head_;
  while (cur != nullptr) {
    os << cur->letter_;
    cur = cur->next_;
  }
}


void LinkedList::print_reverse(std::ostream& os) const {
  // TODO(@Student): Task #2
}


void LinkedList::insert_front(const char& value) {
  // TODO(@Student): Task #3
}


void LinkedList::insert_back(const char& value) {
  Node* new_node = new Node(value);
  if (head_ == nullptr) {  // empty list
    head_ = tail_ = new_node;
  } else {
    tail_->next_ = new_node;
    new_node->prev_ = tail_;
    tail_ = new_node;
  }
}


void LinkedList::insert_after(const char& value_to_add, const char& value_to_find) {
  // TODO(@Student): Task #5
}


void LinkedList::insert_before(const char& value_to_add, const char& value_to_find) {
  // TODO(@Student): Task #6
}


void LinkedList::remove(const char& value) {
  // TODO(@Student): Task #4
}


std::ostream& operator<<(std::ostream& os, const LinkedList& other) {
  other.print(os);
  return os;
}
