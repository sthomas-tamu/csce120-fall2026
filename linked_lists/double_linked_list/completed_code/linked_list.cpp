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
  Node* cur = head_;
  while (cur != nullptr && cur->letter_ != value)
    cur = cur->next_;
  return cur;
}


void LinkedList::print(std::ostream& os) const {
  Node* cur = head_;
  while (cur != nullptr) {
    os << cur->letter_;
    cur = cur->next_;
  }
}


void LinkedList::print_reverse(std::ostream& os) const {
  Node* cur = tail_;
  while (cur != nullptr) {
    os << cur->letter_;
    cur = cur->prev_;
  }
}


void LinkedList::insert_front(const char& value) {
  Node* new_node = new Node(value);
  if (head_ == nullptr) {  // empty list
    head_ = tail_ = new_node;
  } else {
    new_node->next_ = head_;
    head_->prev_ = new_node;
    head_ = new_node;
  }
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
  Node* new_node = new Node(value_to_add);
  if (head_ == nullptr) {
    head_ = tail_ = new_node;
  } else {
    Node* cur = find(value_to_find);
    if (cur == nullptr)  // if not found, insert at end
      cur = tail_;

    // update new_node next_ and prev_
    new_node->next_ = cur->next_;
    new_node->prev_ = cur;

    // update after insertion
    if (cur->next_ == nullptr)  // new tail_
      tail_ = new_node;
    else
      cur->next_->prev_ = new_node;

    // update before insertion
    cur->next_ = new_node;
  }
}


void LinkedList::insert_before(const char& value_to_add, const char& value_to_find) {
  Node* new_node = new Node(value_to_add);
  if (head_ == nullptr) {
    head_ = tail_ = new_node;
  } else {
    Node* cur = find(value_to_find);
    if (cur == nullptr)  // if not found, insert at beginning
      cur = head_;

    // update new_node next_ and prev_
    new_node->next_ = cur;
    new_node->prev_ = cur->prev_;

    // update before insertion
    if (cur == head_)  // cur->prev_ == nullptr
      head_ = new_node;
    else
      cur->prev_->next_ = new_node;

    // update after insertion
    cur->prev_ = new_node;
  }
}


void LinkedList::remove(const char& value) {
  Node* cur = find(value);
  if (cur != nullptr) {
    if (cur == tail_)
      tail_ = cur->prev_;
    else
      cur->next_->prev_ = cur->prev_;

    if (cur == head_)
      head_ = cur->next_;
    else
      cur->prev_->next_ = cur->next_;

    delete cur;
  }
}


std::ostream& operator<<(std::ostream& os, const LinkedList& other) {
  other.print(os);
  return os;
}
