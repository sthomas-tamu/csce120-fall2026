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


int LinkedList::pop_front() {
  // if list is empty, return 0
  if (empty())
    return 0;

  // get first value, advance head_
  Node* cur = head_;
  int result = cur->data_;
  head_ = cur->next_;
  // if list is now empty (only had 1 element before), set tail_ to nullptr
  if (empty())
    tail_ = nullptr;
  delete cur;  // no memory leaks!
  return result;
}


int LinkedList::pop_back() {
  if (empty())
    return 0;

  // get last value
  int result = tail_->data_;

  // if only 1 element, clear list
  if (head_ == tail_) {
    clear();
    return result;
  }

  // find node right before tail_ so can set it as the new tail_
  Node* cur = head_;
  while (cur->next_ != tail_)
    cur = cur->next_;
  delete tail_;
  cur->next_ = nullptr;
  tail_ = cur;
  return result;
}


void LinkedList::remove_duplicates() {
  // cannot have duplicates if list is empty or only has 1 item
  if (empty() || head_ == tail_)
    return;

  // keep a list of items seen so far
  LinkedList seen;
  seen.insert_back(head_->data_);

  Node* prev = head_;
  Node* cur = prev->next_;

  while (cur != nullptr) {
    if (seen.contains(cur->data_)) {  // if seen, remove cur and advance it to the next_
      prev->next_ = cur->next_;
      delete cur;
      cur = prev->next_;
    } else {  // if not seen, add to list and advance both prev and cur
      seen.insert_back(cur->data_);
      prev = cur;
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


unsigned int LinkedList::count(int value) const {
  unsigned int cnt = 0;
  Node* cur = head_;
  while (cur != nullptr) {
    if (cur->data_ == value)
      cnt++;
    cur = cur->next_;
  }
  return cnt;
}


void LinkedList::multiply(int value) {
  Node* cur = head_;
  while (cur != nullptr) {
    cur->data_ *= value;
    cur = cur->next_;
  }
}


void LinkedList::get_evens(LinkedList& new_list) const {
  new_list.clear();
  Node* cur = head_;
  while (cur != nullptr) {
    if (cur->data_ % 2 == 0)
      new_list.insert_back(cur->data_);
    cur = cur->next_;
  }
}


std::ostream& operator<<(std::ostream& os, const LinkedList& ll) {
  ll.print(os);
  return os;
}
