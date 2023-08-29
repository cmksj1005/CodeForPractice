#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Animal {
  string name;
protected:
  Animal(string nm = "Buddy");
public:
  void setName(string nm);
  string getName() const;
};

#endif