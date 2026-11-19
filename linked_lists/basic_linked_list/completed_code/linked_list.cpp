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
  Node* cur = head_;
  while (cur != nullptr) {
    if (cur->data_ == value_to_find) {
      Node* new_node = new Node(value_to_insert);
      new_node->next_ = cur->next_;
      cur->next_ = new_node;
      if (cur == tail_)
        tail_ = cur->next_;
      return;  // only insert after the first occurrance
    }
    cur = cur->next_;
  }
}


void LinkedList::remove(int value) {
  // check if empty list
  if (head_ == nullptr)
    return;

  // check case that list only has 1 element
  if (head_ == tail_) {
    if (head_->data_ == value) {
      delete head_;
      head_ = tail_ = nullptr;
    }
    return;
  }

  // check case that head_ matches
  if (head_->data_ == value) {
    Node* node_to_remove = head_;
    head_ = head_->next_;
    delete node_to_remove;
    return;
  }

  // check if next_ element matches, if so remove it
  // make sure to update tail_ if you remove the last item
  Node* cur = head_;
  while (cur->next_ != nullptr) {
    if (cur->next_->data_ == value) {
      Node* node_to_remove = cur->next_;
      cur->next_ = cur->next_->next_;
      delete node_to_remove;
      if (cur->next_ == nullptr)
        tail_ = cur;
      return;
    } else {
      cur = cur->next_;
    }
  }
}


bool LinkedList::contains(int value) const {
  Node* cur = head_;
  while (cur != nullptr) {
    if (cur->data_ == value)
      return true;
    cur = cur->next_;
  }
  return false;
}


std::ostream& operator<<(std::ostream& os, const LinkedList& ll) {
  ll.print(os);
  return os;
}
