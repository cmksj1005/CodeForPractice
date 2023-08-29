#ifndef CAT_H
#define CAT_H

//#include "Animal.h"

#ifdef ANIMAL_H
class Cat : public Animal {
#else
class Cat {
#endif
  int cattiness{};
  bool landsOnFeet{};
public:
  Cat(int ct = 50, bool lof = true);
  void meow() const;
  void display() const;
};
#endif