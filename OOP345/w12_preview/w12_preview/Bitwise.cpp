#include <iostream>
#include <typeinfo>
using namespace std;

//#define ex1
//#define ex2
//#define ex3
//#define ex4
//#define ex5

template <typename T>
void printBitsNegated(T x){
  cout << typeid(T).name() << " x: " << x << " ~x: " << ~x << " ~~x: " << ~~x << endl;
}

struct Person {
  unsigned int age : 3;
  unsigned int : 0; // padding for alignment
  unsigned int weight : 4;
} Human;

int main() {

#ifdef ex1
  unsigned int x = 32;
  printBitsNegated(x);
  int y = 32;
  printBitsNegated(y);
#endif

#ifdef ex2
  unsigned int x = 12;
  cout << "x : " << x << " (x << 1): " << (x << 1) << endl;
  cout << "x : " << x << " (x << 2): " << (x << 2) << endl;

  unsigned int y = 12;
  cout << "y : " << x << " (y >> 2): " << (y >> 1) << endl;
  cout << "y : " << x << " (y >> 2): " << (y >> 2) << endl;
#endif

#ifdef ex3
  unsigned int x = 11;
  unsigned int y = 2;
  cout << "x: " << x << " y: " << y << " x & y: " << (x & y) << endl;

  // oddness-test
  cout << "oddness-test" << endl;
  int val = 1;
  bool odd = false;
  do {
    cin >> val;
    odd = val & 1;
    cout << val << (odd ? " odd" : " even") << endl;
  } while (val != 0);

  // remainder
  cout << "oddness-test" << endl;
  cout << "11 & (1 - 1): " << (x & (1 - 1)) << " 11 % 1 " << (x % 1) << endl;
  cout << "11 & (2 - 1): " << (x & (2 - 1)) << " 11 % 1 " << (x % 2) << endl;
  cout << "11 & (4 - 1): " << (x & (4 - 1)) << " 11 % 1 " << (x % 4) << endl;
  cout << "11 & (8 - 1): " << (x & (8 - 1)) << " 11 % 1 " << (x % 8) << endl;
#endif

#ifdef ex4
  unsigned int x = 11;
  cout << "bitwise or" << endl;
  cout << "x : " << x << " (x | 4): " << (x | 4) << endl;

  cout << "bitwise xor" << endl;
  cout << "x : " << x << " (x ^ 7): " << (x ^ 7) << endl;

  cout << "bitwise xor reverse" << endl;
  unsigned int y = 12;
  cout << "y : " << y << " (y ^ 7): " << (y ^ 7) << endl;
#endif

#ifdef ex5
  Human.age = 999;
  Human.weight = 999;

  cout << "Human age: " << Human.age << endl;
  cout << "Human weight: " << Human.weight << endl;

#endif
}