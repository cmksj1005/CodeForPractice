#include <iostream>
#include "Cat.h"
using namespace std;

#ifdef ANIMAL_H
Cat::Cat(int ct, bool lof) : Animal("Felix") {
#else
Cat::Cat(int ct, bool lof) {
#endif
  cattiness = ct;
  landsOnFeet = lof;
}

void Cat::meow() const {
  cout << "Meow Meow" << endl;
}

void Cat::display() const {
  cout << "Cattiness: " << cattiness << endl;
  landsOnFeet ? (cout << "Lands on ") : (cout << "Doesn't land on ");
  cout << "feet" << endl;
}