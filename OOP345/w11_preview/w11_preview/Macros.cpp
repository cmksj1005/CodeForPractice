// Macros.cpp

#include <iostream>
using namespace std;

int main() {

//#define ex1
//#define ex2
//#define ex3
//#define ex4

#ifdef ex1

#define MAGICNUMBER 563
#define MAGICNUMBER2 12345\
6789

  int num = MAGICNUMBER + 1;
  int num2 = MAGICNUMBER2 + 2;

  cout << "num: " << num << endl;
  cout << "num2: " << num2 << endl;
#endif

#ifdef ex2
#define MAGICADD(NUM) MAGICNUMBER + NUM // Becareful with spaces

  int num3 = MAGICADD(300);
  cout << "num3: " << num3 << endl;

#define MAGICADD2(NUM,NUM2) NUM + NUM2 

  int num4 = MAGICADD2(300, 200);
  cout << "num4: " << num4 << endl;

  int num5 = MAGICADD2(2 * 3, 3 * 2);
  cout << "num5: " << num5 << endl;

#define MAGICMULT(NUM,NUM2) NUM * NUM2

  int num6 = MAGICMULT(2 + 3, 3 + 2);
  cout << "num6: " << num6 << endl;

#define MAGICSQUARE(NUM) NUM * NUM
  int x = 0;
  int num7 = MAGICSQUARE(x++);
  cout << "num7: " << num7 << endl;
  cout << "x: " << x << endl;

#endif

#ifdef ex3
  cout << "The name of the source file    is " << __FILE__ << endl;
  cout << "The date of its pre-processing is " << __DATE__ << endl;
  cout << "The time of its pre-processing is " << __TIME__ << endl;
#endif

#ifdef ex4
#define MAGIC_CAT "Jiji"

  cout << MAGIC_CAT << endl;

#undef MAGIC_CAT

#define MAGIC_CAT "Sakamoto"

  cout << MAGIC_CAT << endl;
#endif 
}