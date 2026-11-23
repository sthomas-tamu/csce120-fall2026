#include <iostream>
#include <vector>
#include <string>

class Animal {
 protected:
  std::string kind_;
  unsigned int num_legs_;

 public:
  Animal(std::string kind, unsigned int num_legs = 4)
    : kind_{kind}, num_legs_{num_legs} {}

  virtual std::string talk() const { return "<animal noises>"; }

  std::string kind() const { return kind_; }
  unsigned int legs() const { return num_legs_; }
};


class Pig : public Animal {
 public:
  Pig() : Animal("pig") {}

  std::string talk() const override { return "oink"; }
};


class Duck : public Animal {
 public:
  Duck(std::string kind = "duck") : Animal(kind, 2) {}

  std::string talk() const override { return "quack"; }
};


class Horse : public Animal {
 public:
  Horse() : Animal("horse") {}

  std::string talk() const override { return "neigh"; }
};


class Fox : public Animal {
 public:
  Fox() : Animal("fox") {}

  std::string talk() const override { return "ring-ding-ding-ding-dingeringeding"; }
};


class Goose : public Duck {
 public:
  Goose() : Duck("goose") {}

  std::string talk() const override { return "honk"; }
};


int main() {
  // create a list of animals pointers, add a pig, duck, and horse
  std::vector<Animal*> animals;
  animals.push_back(new Pig());
  animals.push_back(new Duck());
  animals.push_back(new Horse());
  animals.push_back(new Fox());
  animals.push_back(new Goose());

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

  std::cout << "The farm has:\n";
  for (Animal const* animal : animals)
    std::cout << "\ta " << animal->kind() << " with " << animal->legs() << " legs\n";

  // release memory
  for (Animal* animal : animals)
    delete animal;
}
