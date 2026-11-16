#include "linked_list.h"

int main() {
  std::cout << "== Testing contains ==\n";

  LinkedList ll;
  ll.insert_back(8);
  ll.insert_front(3);
  ll.insert_back(8);
  ll.insert_back(7);
  std::cout << "ll:\n" << ll << std::endl;

  std::cout << "\tll.contains(8) = " << ll.contains(8) << std::endl;
  std::cout << "\tll.contains(3) = " << ll.contains(3) << std::endl;
  std::cout << "\tll.contains(0) = " << ll.contains(0) << std::endl;

  LinkedList ll_empty;
  std::cout << "ll_empty:\n" << ll_empty << std::endl;
  std::cout << "\tll_empty.contains(1) = " << ll_empty.contains(1) << std::endl;

  LinkedList ll_single;
  ll_single.insert_back(1);
  std::cout << "ll_single:\n" << ll_single << std::endl;
  std::cout << "\tll_single.contains(0) = " << ll_single.contains(0) << std::endl;
  std::cout << "\tll_single.contains(1) = " << ll_single.contains(1) << std::endl;


  std::cout << "\n== Testing insert_after ==\n";

  std::cout << "ll:\n" << ll << std::endl;
  ll.insert_after(-1, 7);
  std::cout << "\tll.insert_after(-1, 7): " << ll << std::endl;
  ll.insert_after(-2, 8);
  std::cout << "\tll.insert_after(-2, 8): " << ll << std::endl;
  ll.insert_after(-3, 0);
  std::cout << "\tll.insert_after(-3, 0): " << ll << std::endl;


  std::cout << "\n== Testing remove ==\n";

  std::cout << "ll:\n" << ll << std::endl;
  ll.remove(8);
  std::cout << "\tll.remove(8): " << ll << std::endl;
  ll.remove(8);
  std::cout << "\tll.remove(8): " << ll << std::endl;
  ll.remove(8);
  std::cout << "\tll.remove(8): " << ll << std::endl;
  ll.remove(-1);
  std::cout << "\tll.remove(-1): " << ll << std::endl;
  ll.remove(3);
  std::cout << "\tll.remove(3): " << ll << std::endl;
  ll.remove(7);
  std::cout << "\tll.remove(7): " << ll << std::endl;
  ll.remove(-2);
  std::cout << "\tll.remove(-2): " << ll << std::endl;
  ll.remove(-2);
  std::cout << "\tll.remove(-2): " << ll << std::endl;

  return 0;
}
