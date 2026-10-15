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
  bool operator==(const Dice& rhs) const;
  bool operator!=(const Dice& rhs) const;
};

#endif  // DICE_H_
