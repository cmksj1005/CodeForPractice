#ifndef DOG_H
#define DOG_H

//#include "Animal.h"

#ifdef ANIMAL_H
class Dog : public Animal {
#else
class Dog{
#endif
  int dogginess{};
  bool enjoysWalks{};

public:
  Dog(int dg = 50, bool ew = true);
  void bark() const;
  void display() const;
};

#endif