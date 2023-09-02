#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <thread>
#include <vector>
using namespace std;

struct Gem {
  string name;
  string colour;
  int shine;
  bool polished;
};

/*
 Create a Box class has the following properties:
•	An STL container of Gems as a data member
•	A += operator that adds Gems to the box
•	A -= operator that removes Gems from the Box based on a given string (name) to search for.
  If the string is found then remove any Gems that match. If there isn’t a match at all then throw an
  exception of string type with a relevant error message
•	A function called process that doesn’t receive any parameters nor returns any value.
  This function will iterate through the Gems in the Box and polish them if they aren’t yet polished.
  Polishing a Gem will cause its shine value to increase by 20. For this functionality incorporate the use of threads to divide the work.
•	A display function that displays the contents of the box
•	As an extra task, modify the Box class to instead have a container of Gem pointers and apply the use of smart pointers to the solution.
*/

class Box {
  vector<Gem> gems;
public:
  Box& operator+=(const Gem& g) {
    gems.push_back(g);
    return *this;
  }
  
  Box& operator-=(const string& name) {
    //for (auto& x : gems) {
    //  if (x.name == name) {
    //    gems.erase(&x);
    //  }
    //}

    //bool matches{ false };
    //for (auto x = gems.begin(); x != gems.end(); x++) {
    //  if (x->name == name) {
    //    gems.erase(x);
    //    matches = true;
    //  }
    //}

    //if (!matches) {
    //  //string err{ "No matches found!" };
    //  //throw err;
    //  throw std::string("No Matches found!"); // this throws an std::string
    //  throw "No Matches Found!"; // this throws a const char*
    //}

    size_t cnt = gems.size();
    auto itr = remove_if(gems.begin(), gems.end(), [name](const Gem& g) {
      return g.name == name;
    });

    //if (itr == gems.end()) {
    //  throw std::string("No Matches found!"); // this throws an std::string
    //}

    gems.resize(itr - gems.begin());

    if (cnt == gems.size()) {
      throw std::string("No Matches found!"); // this throws an std::string
    }

    return *this;
  }
  
  void process() {
    //for (auto& x : gems) {
    //  if (!x.polished) {
    //    x.polished = true;
    //    x.shine += 20;
    //  }
    //}

    auto polish = [](vector<Gem>::iterator beg, vector<Gem>::iterator end) {
      for (auto x = beg; x != end; x++) {
        if (!x->polished) {
          x->polished = true;
          x->shine += 20;
        }
      }
    };

    auto start = gems.begin();
    auto half = gems.begin() + gems.size() / 2;
    auto end = gems.end();

    thread t1, t2;
    // give task to threads...
    t1 = thread(polish, start, half);
    t2 = thread(polish, half, end);
    t1.join();
    t2.join();

  }

  void display() const {
    for (auto& g : gems) {
      cout << g.name << endl;
      cout << g.colour << endl;
      cout << g.shine << endl;
      cout << g.polished << endl;
    }
  }
};

int main() {
  Box b;

  cout << "\nAdding Gems" << endl;
  b += Gem{ "Emerald", "Green", 20, false };
  b += Gem{ "Ruby", "Red", 50, true };
  b += Gem{ "Sapphire", "Blue", 80, false };
  b += Gem{ "Onyx", "Black", 60, false };
  b += Gem{ "Opal", "White", 10, false };
  b.display();

  cout << "\nRemoving Gems" << endl;
  try {
    b -= "Ruby";
    b -= "Emerald";
    b -= "Diamond";
    b.display();
  }
  catch (string c) {
    cout << c << endl;
  }

  cout << "\nPolishing Gems" << endl;
  b.process();
  b.display();


  cout << "\nVector of Boxes" << endl;
  vector<Box*> boxes;
  boxes.push_back(new Box());
  boxes.push_back(new Box());
  boxes.push_back(new Box());

  for (auto x : boxes) {
    x->operator+=(Gem{ "Emerald", "Green", 20, false });
    x->operator+=(Gem{ "Ruby", "Red", 90, false });
    x->operator+=(Gem{ "Sapphire", "Blue", 40, false });
  }

  for (auto x : boxes) {
    delete x;
  }
}
