#include <iostream>

#include "BankAccount.h"

int main() {
  BankAccount ba(1234, "Maggie Aggie", 100);
  ba.print();

  std::cout << "\nDepositing $50\n";
  if (ba.deposit(50)) {
    ba.print();
  } else {
    std::cout << "\tdeposit failed\n";
  }

  std::cout << "\nDepositing $-100\n";
  if (ba.deposit(-100)) {
    ba.print();
  } else {
    std::cout << "\tdeposit failed\n";
  }

  for (int i = 0; i < 2; ++i) {
    std::cout << "\nWithrawing $100\n";
    if (ba.withdraw(100)) {
      ba.print();
    } else {
      std::cout << "\twithdraw failed\n";
    }
  }

  std::cout << "\nWithdrawing $-100\n";
  if (ba.withdraw(-100)) {
    ba.print();
  } else {
    std::cout << "\twithdraw failed\n";
  }

  return 0;
}
