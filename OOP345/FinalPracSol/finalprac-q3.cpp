// finalprac-q3.cpp
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <numeric>
#include <thread>
#include <future>
// Error1 - Compile Error
// Desc: All the entities in the header are duplicated via the double include below
// This then violates the one definition rule.
// Fix: Incorporate header guards to our header file or don't double include or #pragma once
#include "finalprac-q3.h"
#include "finalprac-q3.h"

TreasureBox::TreasureBox(const std::string* names, unsigned* weights, unsigned size){
  for (unsigned x = 0; x < size; ++x) {
    gems.push_back(Gem{ names[x], weights[x] });
    weight += weights[x];
  }
}

TreasureBox& TreasureBox::operator+=(const Gem& g) {
  gems.push_back(g);
  weight += g.weight;
  return *this;
}

void TreasureBox::update(const std::string& name) {
  std::vector<Gem>::iterator itr;
  for (itr = gems.begin(); itr != gems.end(); ++itr) {
    if (itr->name == name) {
      unsigned sum = 0;
      sum = std::accumulate(name.begin(), name.end(), 0);
      itr->weight += sum;
    }
  }
}

std::ostream& TreasureBox::display() const {
  std::cout << "TreasureBox Contents" << std::endl;
  for (auto& g : gems) {
    std::cout << g.name << " : " << g.weight << std::endl;
  }
  return std::cout;
}

void task(std::promise<unsigned>& p) {
  Gem gems[]{ {"Red" , 10}, {"Green", 20}, {"Blue", 30} };

  auto idx = std::find_if(gems, gems + 2, [](const Gem& g) {
    return g.name == "Green";
  });

  // Error 6 - Runtime/Undef behavior
  // Desc: The promise doesn't set a value to be gotten by the future object from the main
  // Fix: use the set_value from the promise to set a value to the shared state between it and the future
  p.set_value(idx->weight);
}

int main() {

  std::string strs[]{ "Ruby", "Emerald", "Sapphire", "Opal" };
  unsigned nums[]{ 10, 20, 30, 40 };

  // Error 2 - Compile Error
  // Desc: As TreasureBox has defined an overloaded constructor there is no compiler provided default
  // which is used in this following line to create a dynamice TreasureBox.
  // Fix: Include a default constructor for TreasureBox
  std::unique_ptr<TreasureBox> tbr(new TreasureBox()); 
  std::unique_ptr<TreasureBox> ptr(new TreasureBox(strs, nums, 4));
 
  std::string_view sv = "Ruby";
  std::string s = "Opal";
  // Error 3 - Compile Error
  // Desc: Type mismatch betweeen parameter and passed in argument (string_views are not implictly castable/interoperable)
  // with std::string.
  // Fix: Cast the sv as string, or use some member from sv or pass a string to update instead
  ptr->update(sv); 
  ptr->update(s);
  ptr->display();

  // Error 4 - Compile
  // Desc: There is no overload for the += for Gem and Gem
  // Fix: Make an overload for += or just use brackets to change the order of ops to the TB += Gem first
  *ptr += Gem{ "Diamond", 50 } += Gem{ "Amber", 60 }; 
  // *ptr += Gem += Gem
  // TB += Gem += Gem
  (*ptr += Gem{ "Pearl", 70 }).display();
  // (*ptr += Gem).display
  // (TB += Gem).display
  // (TB).display
  // ostream

  std::promise<unsigned> pro;
  std::future<unsigned> fut = pro.get_future();

  std::thread t1;
  // Error 5 - Runtime Error (Crash)
  // Desc: Thread t1 is in a unjoinable state (no id, no task) and it attempts to call join()
  // Fix: Don't call join till after becoming joinable (id, task)
  t1.join(); 
  t1 = std::thread(task, std::ref(pro));
  std::cout << "Promised Future: " << fut.get() << std::endl; 
  t1.join();
}
