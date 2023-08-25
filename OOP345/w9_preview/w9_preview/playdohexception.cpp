// playdohexception.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Playdoh {
  char* colour;
  int weight;
public:
  Playdoh(const char* col, int wei) : weight(wei) {
    colour = nullptr;
    if (col != nullptr) {
      colour = new char[strlen(col) + 1];
      strcpy(colour, col);
    }
  }

  ~Playdoh() { delete[] colour; }

  void display(ostream& os) const {
    if (colour[0] == '\0')
      throw "Empty String Colour";
    os << "Playdoh colour: " << colour << " weight: " << weight << endl;
  }
};

ostream& operator<<(ostream& os, const Playdoh& p) {
  p.display(os);
  return os;
}

void asPlaydoh(const char* col) {
  Playdoh* p = new Playdoh(col, 50);
  p->display(cout);
  delete p;
}

int main() {

//#define ex1
//#define ex2
#define ex3 // solution is in smart_ptr

#ifdef ex1
  Playdoh* playptr = new Playdoh("Red", 10);
  cout << *playptr;
  delete playptr;
  playptr = new Playdoh("", 20);
  cout << *playptr;
  delete playptr;
#endif
#ifdef ex2
  Playdoh* playptr = new Playdoh("", 20);
  try {
    cout << *playptr;
  }
  catch (const char* e) {
    cout << "Caught : " << e << endl;
    delete playptr;
  }
#endif

#ifdef ex3
  try {
    asPlaydoh("Blue");
    asPlaydoh("Green");
    asPlaydoh("");
  }
  catch (const char* e) {
    cout << "Caught: " << e << endl;
  }
#endif

}
//Check the point which destructor doesn't delete the dynamic memory. Smart pointer solves the problem.
