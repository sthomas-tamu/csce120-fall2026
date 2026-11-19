#include "linked_list.h"

LinkedList::LinkedList(const LinkedList& other)
  : head_{nullptr}, tail_{nullptr} {
  Node* cur = other.head_;
  while (cur != nullptr) {
    insert_back(cur->data_);
    cur = cur->next_;
  }
}


LinkedList& LinkedList::operator=(const LinkedList& other) {
  if (this == &other)
    return *this;

  clear();
  Node* cur = other.head_;
  while (cur != nullptr) {
    insert_back(cur->data_);
    cur = cur->next_;
  }
  return *this;
}


void LinkedList::clear() {
  while (head_ != nullptr) {
    Node* node_to_delete = head_;
    head_ = head_->next_;
    delete node_to_delete;
  }
  // head_ is nullptr when loop exits

  tail_ = nullptr;
}


void LinkedList::print(std::ostream& os) const {
  Node* cur = head_;
  if (cur == nullptr)
    os << "Empty List! ";
  while (cur != nullptr) {
    os << cur->data_ << " ";
    cur = cur->next_;
  }
}


void LinkedList::insert_front(int value) {
  Node* new_node = new Node(value);
  new_node->next_ = head_;
  head_ = new_node;
  if (tail_ == nullptr) {  // empty list
    tail_ = new_node;
  }
}


void LinkedList::insert_back(int value) {
  Node* new_node = new Node(value);  // new_node->next_ is set to nullptr in its constructor
  if (tail_ == nullptr) {  // empty list
    head_ = tail_ = new_node;
  } else {
    tail_->next_ = new_node;
    tail_ = new_node;
  }
}


void LinkedList::insert_after(int value_to_insert, int value_to_find) {
  // TODO(@Student): Task 2
}


void LinkedList::remove(int value) {
  // TODO(@Student): Task 3
}


bool LinkedList::contains(int value) const {
  // TODO(@Student): Task 1
  return false;
}


std::ostream& operator<<(std::ostream& os, const LinkedList& ll) {
  ll.print(os);
  return os;
}
