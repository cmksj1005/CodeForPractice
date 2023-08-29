#include <iostream>
#include "Dog.h"
using namespace std;

#ifdef ANIMAL_H
Dog::Dog(int dg, bool ew) : Animal("Wishbone") {
#else
Dog::Dog(int dg, bool ew) {
#endif
  dogginess = dg;
  enjoysWalks = ew;
}

void Dog::bark() const {
  cout << "Woof Woof" << endl;
}

void Dog::display() const {
  cout << "Dogginess: " << dogginess << endl;
  enjoysWalks ? (cout << "Likes ") : (cout << "Doesn't like ");
  cout << "walks" << endl;
}
