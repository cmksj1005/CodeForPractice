// Dynamically Allocated 2d Arrays
 // dynamic2D.cpp

#include <iostream>
#include <iomanip>

int main() {
  int c, r;
  int** a;  // points to row addresses

  std::cout << "Number of rows : ";
  std::cin >> r;
  std::cout << "Number of columns : ";
  std::cin >> c;

  a = new int* [r]; // for row addresses

  for (int i = 0; i < r; i++)
    a[i] = new int[c]; // for elements
                       // of row i
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      a[i][j] = (i + 1) * (j + 1);

  std::cout << "   ";
  for (int j = 0; j < c; j++)
    std::cout << std::setw(4) << j + 1;
  std::cout << std::endl;
  for (int i = 0; i < r; i++) {
    std::cout << std::setw(3) << i + 1;
    for (int j = 0; j < c; j++)
      std::cout << std::setw(4) << a[i][j];
    std::cout << std::endl;
  }

  for (int i = 0; i < r; i++)
    delete[] a[i]; // deallocate row i
  delete[] a; // deallocate pointers to rows
}