#include <iostream>
using namespace std;
int main() {
    int arr[3]; // [1, 2, 3];
    int* arrptr = new int[3]; // [1, 2, 3];
    // array of pointers
    int* ptrarr[3]; // [ *, *, *]
    ptrarr[0] = new int{ 1 };
    ptrarr[1] = new int{ 2 };
    ptrarr[2] = new int{ 3 };
    for (auto i = 0; i < 3; ++i)
        delete ptrarr[i];
    // composition
    int** ptrarr2 = nullptr; // ??? size of arr
    ptrarr2 = new int* [3]; // [*, *, *];
    ptrarr2[0] = new int{ 1 }; // [ * -> 1, * -> 2, * -> 3]
    ptrarr2[1] = new int{ 2 };
    ptrarr2[2] = new int{ 3 };
    for (auto i = 0; i < 3; ++i)
        delete ptrarr2[i];
    delete[]ptrarr2;
    // agg
    int** ptrarr3 = nullptr; // ??? size of arr
    ptrarr3 = new int* [3]; // [*, *, *]
    int a{ 1 }, b{ 2 }, c{ 3 };
    ptrarr3[0] = &a;
    ptrarr3[1] = &b;
    ptrarr3[2] = &c;
    delete[] ptrarr3;
}