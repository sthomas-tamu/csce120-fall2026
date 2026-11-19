#ifndef MORSE_CODE_H_
#define MORSE_CODE_H_

#include <iostream>

class MorseCode {
  char* code_;
  unsigned int length_;

 public:
  // default constructor
  MorseCode() : code_ {nullptr}, length_{0} {}

  // constructor with initial symbols
  MorseCode(const char* c, unsigned int l);

  // copy constructor
  MorseCode(const MorseCode& source);

  // destructor
  ~MorseCode();

  // copy assignment operator
  MorseCode& operator=(const MorseCode& source);

  // concat operator
  //   add a space only if both codes are not empty
  MorseCode operator+(const MorseCode& other) const;

  // print (used by operator<< so don't have to provide getter methods)
  std::ostream& print(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const MorseCode& mc);

#endif
