#include <list>
#include <iostream>
using namespace std;
int main() {
   std::list<double> prices;  // initially empty

   prices.push_back(10.43);   // add 10.43
   prices.push_back(20.54);   // add 20.54
   prices.push_back(32.43);   // add 32.43
   prices.insert(--prices.end(), 12.52);
   prices.erase(++prices.begin());

   //for (int i = 0; i < prices.size(); i++) {
   //    std::cout << prices[i] << std::endl;
   //}

   //begin() returns std::list<double>::iterator
   for (auto i = prices.begin(); i != prices.end(); i++)
      std::cout << *i << "  "; // i is a pointer
   std::cout << std::endl;

   for (auto& x : prices) { // require begin, end
       cout << x << endl;
   }

   //수업시간에 추가한 코드 다 쳐놓고 내가 저장을 안한 것 같으니까 확인

   return 0;
}