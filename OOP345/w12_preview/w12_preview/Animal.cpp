#include <iostream>
#include "Animal.h"
using namespace std;

Animal::Animal(string nm) {
  name = nm;
}

void Animal::setName(string nm) {
  name = nm;
}

string Animal::getName() const {
  return name;
}
