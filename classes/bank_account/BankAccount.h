#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>

class BankAccount {
 public:
  BankAccount(unsigned int, const std::string&, double);

  double get_balance() const;

  bool deposit(double amt);
  bool withdraw(double amt);

  void print() const;

 private:
  // data members
  unsigned int account_number_;
  std::string owner_;
  double balance_;
};

#endif
