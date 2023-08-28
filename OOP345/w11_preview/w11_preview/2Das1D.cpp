#include <iostream>
using namespace std;

int main() {

  int r, c;

  cout << "Number of rows : ";
  cin >> r;
  cout << "Number of columns : ";
  cin >> c;

  int* arr1 = new int[r * c];

  for (auto i = 0; i < r; i++) {
    for (auto j = 0; j < c; j++) {
      arr1[i * r + j] = i * j; // Notice the subscripting
    }
  }

  for (auto i = 0; i < r * c; i++) {
    if (i % r == 0 && i != 0) cout << endl;
    cout << arr1[i] << ",";
  }

  delete[] arr1;
}