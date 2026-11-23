#include <iostream>
#include <vector>
#include <string>

class Animal {
  std::string kind_;

 public:
  Animal(std::string kind) : kind_{kind} {}

  virtual std::string talk() const { return "<animal noises>"; }

  std::string kind() const { return kind_; }
};


class Pig : public Animal {
 public:
  Pig() : Animal("pig") {}

  std::string talk() const override { return "oink"; }
};


class Duck : public Animal {
 public:
  Duck() : Animal("duck") {}

  std::string talk() const override { return "quack"; }
};


class Horse : public Animal {
 public:
  Horse() : Animal("horse") {}

  std::string talk() const override { return "neigh"; }
};


int main() {
  // create a list of animals pointers, add a pig, duck, and horse
  std::vector<Animal*> animals;
  animals.push_back(new Pig());
  animals.push_back(new Duck());
  animals.push_back(new Horse());
  // TODO(@Student): add a Fox to the list

  for (Animal const* animal : animals) {
    std::cout
      << "Old MacDonald had a farm, E-I-E-I-O.\n"
      << "And on that farm he had a " << animal->kind() << ". E-I-E-I-O.\n"
      << "With a " << animal->talk() << ' ' << animal->talk() << " here.\n"
      << "And a " << animal->talk() << ' ' << animal->talk() << " there.\n"
      << "Here a " << animal->talk() << ".\n"
      << "There a " << animal->talk() << ".\n"
      << "Everywhere a " << animal->talk() << ' ' << animal->talk() << ".\n"
      << "Old MacDonald had a farm, E-I-E-I-O.\n"
      << std::endl;
  }

  // release memory
  for (Animal* animal : animals)
    delete animal;
}
