#include <iostream>
#include "Dog.h"
#include "Cat.h"
using namespace std;

class CatDog : public Cat, public Dog {
  int catdoginess{};

public:
  CatDog(int cat, int dog, bool lof, bool ew) : Cat(cat, lof), Dog(dog, ew) {
    catdoginess = cat + dog;
  }

  void call() const {
    meow();
    bark();
  }
  void display() const {
    cout << "The catdoginess of this CatDog is: " << catdoginess << endl;
    cout << "The cat traits: " << endl;
    Cat::display();
    cout << "The dog traits: " << endl;
    Dog::display();
  }

};

int main() {

  CatDog cd(60, 70, true, true);
  cd.call();
  cd.display();

  cout << "Animal Name: " << cd.getName() << endl;
  cout << "Cat Name: " << cd.Cat::getName() << endl;
  cout << "Dog Name: " << cd.Dog::getName() << endl;

}