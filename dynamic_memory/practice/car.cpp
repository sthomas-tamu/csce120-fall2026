#include <iostream>
#include <string>

class Engine {
  int horsepower_;

 public:
  Engine(int hp = 0) : horsepower_{hp} {}

  int horsepower() const { return horsepower_; }
  void set_horsepower(int hp) { horsepower_ = hp; }
};

class Car {
  std::string model_;
  Engine* motor_;

 public:
  Car(const std::string& m, int hp) : model_{m}, motor_{new Engine{hp}} {}

  Car(const Car& source) : model_(source.model_), motor_{nullptr} {
    if (source.motor_ != nullptr)
      motor_ = new Engine(source.motor_->horsepower());
  }

  ~Car() {
    delete motor_;
  }

  int horsepower() const { return motor_->horsepower(); }

  void upgrade(int new_hp) { motor_->set_horsepower(new_hp); }
};

int main() {
  Car car1("Tesla", 300);
  Car car2 = car1;
  car1.upgrade(400);

  std::cout << car1.horsepower() << "," << car2.horsepower();
  return 0;
}
