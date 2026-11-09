#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(unsigned int account_number, const std::string& owner, double balance)
  : account_number_(account_number), owner_(owner), balance_(balance)
{}

double BankAccount::get_balance() const {
  return balance_;
}

bool BankAccount::deposit(double amt) {
  // don't allow deposit of negative amounts
  if (amt < 0) {
    return false;
  }

  balance_ += amt;
  return true;
}

bool BankAccount::withdraw(double amt) {
  // don't allow withdraw of negative amounts
  if (amt < 0) {
    return false;
  }

  // don't allow balance_ to go below 0
  if (amt > balance_) {
    return false;
  }

  balance_ -= amt;
  return true;
}

void BankAccount::print() const {
  std::cout << "Bank Account [" << account_number_ << "]:\t" << owner_ << "\n";
  std::cout << "\t" << balance_ << std::endl;
}
