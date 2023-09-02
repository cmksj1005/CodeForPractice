#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {

  vector<int> a{ 1,2,3,4,5 };

  auto itr = remove_if(a.begin(), a.end(), [](int i) {
    return i % 2 == 0;
  });

  // 1, 3, 5, 4, 5
  //          ^ itr
  // ^ begin
  //                 ^ end

  //a.resize(itr - a.begin());
  a.erase(itr, a.end());

  for (auto& i : a) {
    cout << "Num: " << i << endl;
  }

  cout << "Size of vec: " << a.size() << endl;

  // Num: 1
  // Num: 3
  // Num: 5
}