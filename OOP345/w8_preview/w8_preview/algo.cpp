// algo.cpp
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Playdoh {
  string colour { };
  int weight { 0 };
public:
  Playdoh() {}
  Playdoh(int wei) : colour("Pink"), weight(wei){}
  Playdoh(const char* col, int wei) : colour(col), weight(wei) {}
  std::ostream& display(std::ostream& os) const {
    os << "Playdoh Colour: " << colour << " Weight: " << weight << endl;
    return os;
  }
  void setColour(const char* col) { colour = col; }
  void setWeight(int wei) { weight = wei; }
  string getColour() const { return colour; }
  int getWeight() const { return weight; }

  bool operator==(string col) const { return colour == col; }
  operator int() const { return weight; }

};

std::ostream& operator<<(std::ostream& os, const Playdoh& p) {
  p.display(os);
  return os;
}

int main() {
  vector<Playdoh> ps = {
    {"Red", 22},
    {"Red", 24},
    {"Blue", 29},
    {"Blue", 23},
    {"Blue", 25},
    {"Red", 21},
    {"White", 90},
    {"Yellow", 40},
    {"Green", 50}
  };

//#define que
//#define mod
//#define mani
#define numeric

  cout << "Print out the original Playdoh Vector" << endl;
  for (auto& x : ps) {
    cout << x;
  }

  // Queries
#ifdef que
  cout << "\n***********Queries************" << endl;
  // bool all_of(InputIterator f, InputIterator l, Fn predicate)
  if (!all_of(ps.begin(), ps.end(), [](Playdoh p) { return p.getColour() == "Red"; }))
    cout << "Not All of the Playdohs are Red" << endl;

  //bool any_of(InputIterator f, InputIterator l, Fn predicate)
  if (any_of(ps.begin(), ps.end(), [](Playdoh p) { return p.getColour() == "Red"; }))
    cout << "At least one of the Playdoh is Red" << endl;

  //bool none_of(InputIterator f, InputIterator l, Fn predicate)
  if (none_of(ps.begin(), ps.end(), [](Playdoh p) { return p.getColour() == "Pink"; }))
    cout << "None of the Playdohs are Pink" << endl;

  // Fn for_each(InputIterator f, InputIterator l, Fn predicate)
  int ints[]{ 1, 2, 3, 4, 5, 6, 7, 8 };
  for_each(ints, ints + 5, [](auto p) { cout << p << ", "; });

  // InputIterator find(InputIterator f, InputIterator l, const T& t)
  vector<Playdoh>::iterator itr;
  itr = find(ps.begin(), ps.end(), "White");
  if (itr != ps.end()) {
    cout << endl << *itr;
    cout << "Found at position: " << itr - ps.begin() << endl;
  }

  // int count_if(InputIterator f, InputIterator l, Fn predicate)
  int counter = count_if(ps.begin(), ps.end(), [](Playdoh& p) { return p.getColour() == "Red"; });
  cout << "We have " << counter << " Red Playdoh in the Vector" << endl;
#endif

  // Modifiers
#ifdef mod
  cout << "\n***********Modifiers************" << endl;
  vector<int> dohweights(ps.size(), 1);
  vector<Playdoh> ps2(ps.size(), Playdoh());

  // OutputIterator transform(InputIterator f, InputIterator l, OutputIterator o, Fn u)
  transform(ps.begin(), ps.end(), dohweights.begin(), [](Playdoh& p) { return int(p); });
  cout << "Print out the dohweight Vector" << endl;
  for (auto& x : dohweights) {
    cout << x << endl;
  }

  // OutputIterator transform(InputIterator f, InputIterator l, InputIterator g, OutputIterator o, Fn b)
  transform(ps.begin(), ps.end(), dohweights.begin(), ps2.begin(), plus<int>());
  cout << "Print out the transformed Playdoh Vector" << endl;
  for (auto& x : ps2) {
    cout << x;
  }

  // void replace_if(ForwardIterator f, ForwardIterator l, Fn predicate, const T& t)
  replace_if(ps2.begin(), ps2.end(), [](const Playdoh& p) { return p.getColour() == "Pink"; }, Playdoh("Red", 99));
  cout << "Print out the replaced Playdoh Vector" << endl;
  for (auto& x : ps2) {
    cout << x;
  }

#endif

  // Manipulators
#ifdef mani
  cout << "\n***********Manipulators************" << endl;
  // void sort(RandomAccessIterator f, RandomAccessIterator l)
  cout << "sorted" << endl;
  sort(ps.begin(), ps.end()); // ascending
  sort(ps.begin(), ps.end(), [](const Playdoh& ps1, const Playdoh& ps2) { return ps1 > ps2; }); // descending
  sort(ps.begin(), ps.end(), greater<Playdoh>());
  for (auto& x : ps) {
    cout << x;
  }

  cout << "merged" << endl;
  int first[] = { 10,15,5,20,25 };
  int second[] = { 50,40,30,20,10 };
  std::vector<int> v(10);
  sort(first, first + 5); // 5, 10, 15, 20, 25
  sort(second, second + 5); // 10, 20, 30, 40, 50
  //OutputIterator merge(InputIterator f1, InputIterator l1, InputIterator f2, InputIterator l2, OutputIterator o)
  merge(first, first + 5, second, second + 5, v.begin());
  for (auto& x : v) {
    cout << x << ", ";
  }
  cout << endl;

#endif mani

#ifdef numeric
  cout << "\n***********Numeric************" << endl;
  //T accumulate(InputIterator f, InputIterator l, T init)
  //T accumulate(InputIterator f, InputIterator l, T init, Fn pred)
  int weightSum = accumulate(ps.begin(), ps.end(), 0);
  cout << "The sum of the playdoh vector's weight is: " << weightSum << endl;

  int stuff = accumulate(ps.begin(), ps.end(), 0, [](const int& result, const Playdoh& p) {
    return result + (p.getColour())[0];
  });
  cout << "The sum of the playdoh vector's colour is: " << stuff<< endl;

  int arr1[]{ 1, 2, 3, 4 };
  int arr2[]{ 1, 2, 3, 4 };

  //T inner_product(InputIterator f1, InputIterator l1, InputIterator f2, T init)
  int innerprod = inner_product(arr1, arr1+4, arr2, 0); // for fun
  cout << "The inner_product of arr1 and arr2 is: " << innerprod << endl;

  vector<int> partialsum(4, 0);
  //OutputIterator partial_sum(InputIterator f1, InputIterator l1, OutputIterator partialSum)
  partial_sum(arr1, arr1+4, partialsum.begin()); // for fun
  for (auto& x : partialsum) {
    cout << x << ", ";
  }

#endif
}
