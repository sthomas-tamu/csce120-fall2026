#include "linked_list.h"

int main() {
  std::cout << "== Testing count ==\n";

  LinkedList ll;
  ll.insert_back(8);
  ll.insert_front(3);
  ll.insert_back(7);
  ll.insert_back(8);
  std::cout << "ll:\n" << ll << std::endl;

  std::cout << "ll.count(8) = " << ll.count(8) << std::endl;
  std::cout << "ll.count(3) = " << ll.count(3) << std::endl;
  std::cout << "ll.count(0) = " << ll.count(0) << std::endl;

  LinkedList ll_empty;
  std::cout << "ll_empty:\n" << ll_empty << std::endl;
  std::cout << "ll_empty.count(1) = " << ll_empty.count(1) << std::endl;

  LinkedList ll_single;
  ll_single.insert_back(1);
  std::cout << "ll_single:\n" << ll_single << std::endl;
  std::cout << "ll_single.count(0) = " << ll_single.count(0) << std::endl;
  std::cout << "ll_single.count(1) = " << ll_single.count(1) << std::endl;


  std::cout << "== Testing multiply ==\n";

  ll.multiply(3);
  std::cout << "ll:\n" << ll << std::endl;

  ll_empty.multiply(3);
  std::cout << "ll_empty:\n" << ll_empty << std::endl;

  ll_single.multiply(3);
  std::cout << "ll_single:\n" << ll_single << std::endl;


  std::cout << "== Testing get_evens ==\n";

  LinkedList ll_evens, ll_evens_empty;
  ll.get_evens(ll_evens);
  ll_empty.get_evens(ll_evens_empty);
  std::cout << "ll_evens:\n" << ll_evens << std::endl;
  std::cout << "ll_evens_empty:\n" << ll_evens_empty << std::endl;


  std::cout << "== Testing pop_front ==\n";

  std::cout << "ll:\n" << ll << std::endl;
  while (!ll.empty()) {
    std::cout << ll.pop_front() << std::endl;
    std::cout << "ll:\n" << ll << std::endl;
  }
  std::cout << ll.pop_front() << std::endl;
  std::cout << "ll:\n" << ll << std::endl;


  std::cout << "== Testing pop_back ==\n";

  for (int i = 1; i < 4; ++i)
    ll.insert_back(i);
  std::cout << "ll:\n" << ll << std::endl;
  while (!ll.empty()) {
    std::cout << ll.pop_back() << std::endl;
    std::cout << "ll:\n" << ll << std::endl;
  }
  std::cout << ll.pop_back() << std::endl;
  std::cout << "ll:\n" << ll << std::endl;


  std::cout << "== Testing remove_duplicates ==\n";

  ll.insert_back(8);
  ll.insert_front(3);
  ll.insert_back(7);
  ll.insert_back(8);
  std::cout << "ll:\n" << ll << std::endl;
  ll.remove_duplicates();
  std::cout << "ll:\n" << ll << std::endl;
  ll.remove_duplicates();
  std::cout << "ll:\n" << ll << std::endl;

  return 0;
}
