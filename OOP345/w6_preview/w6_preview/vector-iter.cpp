#include <vector>
#include <iostream>
using namespace std;

int main() {
   std::vector<double> prices;  // initially empty
   std::vector<double>::iterator i;

   prices.push_back(10.43); // add 10.43
   prices.push_back(20.54); // add 20.54
   prices.push_back(32.43); // add 32.43
   for (i = prices.begin(); i != prices.end(); i++)
      std::cout << *i << "  ";
   std::cout << std::endl;

   i = prices.begin();
   cout << "First: " << *i << endl;
   i++;
   cout << "Second: " << *i << endl;
   i--;
   cout << "Third: " << *i << endl;

   prices.insert(i, 99.99);
   for (i = prices.begin(); i != prices.end(); i++)
       std::cout << *i << "  ";
   std::cout << std::endl;

//   for (int i = 0; i < prices.size(); i++) {
//    std::cout << prices[i] << std::endl;
//}

   return 0;
}