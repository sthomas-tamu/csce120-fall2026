#ifndef DICE_H_
#define DICE_H_

class Dice {
 private:
  unsigned int sides_;
  unsigned int value_;

 public:
  // Constructor
  Dice(unsigned int n);

  // Getter methods
  unsigned int sides() const;
  unsigned int value() const;

  void roll();

  // Comparison methods
  // TODO(@Class) implement == and !=
};

#endif  // DICE_H_
