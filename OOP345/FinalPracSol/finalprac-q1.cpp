#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

struct ComputerParts {
  string partType;
  string model;
  double price;
  double powerConsumption;
  bool used;
};

int main() {

  vector<ComputerParts> wishList;

  // Task 1
  // Add to the vector some number of desired Computer Parts
  // Eg. GPU, RTX 3080, 1000, 300, false
  wishList.push_back(ComputerParts{"CPU", "AMD 7950X3D", 800, 200, false});
  wishList.push_back(ComputerParts{"GPU", "NVIDIA 3070", 500, 250, false});
  wishList.push_back(ComputerParts{"RAM", "Ripjaws 32GB", 120, 50, true});
  wishList.push_back(ComputerParts{"PSU", "Corsair SFX750", 200, 750, true});
  wishList.push_back(ComputerParts{"MB", "ASRock B550i", 150, 100, false});

  auto display = [](vector<ComputerParts>& wl) {for (auto& x : wl) {
    cout << x.model << "|" << x.partType << endl;
    cout << x.price << "|" << x.powerConsumption << "|" << x.used << endl;
  }};
  display(wishList);
  cout << "*******************" << endl;

  // Task 2
  // Sort the wishList by price in ascending order
  sort(wishList.begin(), wishList.end(), [](const ComputerParts& c1, const ComputerParts& c2) {
    return c1.price < c2.price;
  });
  display(wishList);
  cout << "*******************" << endl;

  // Task 3
  // Print to the screen the part in the wishList that has the most and least powerConsumption
  //sort(wishList.begin(), wishList.end(), [](const ComputerParts& c1, const ComputerParts& c2) {
  //  return c1.powerConsumption < c2.powerConsumption;
  //});
  //cout << wishList.front().partType << endl;
  //cout << wishList.back().partType << endl;
  //cout << "*******************" << endl;

  auto maxItem = max_element(wishList.begin(), wishList.end(), [](const ComputerParts& c1, const ComputerParts& c2) {
    return c1.powerConsumption < c2.powerConsumption;
  });
  auto minItem = min_element(wishList.begin(), wishList.end(), [](const ComputerParts& c1, const ComputerParts& c2) {
    return c1.powerConsumption < c2.powerConsumption;
  });
  
  cout << maxItem->partType << endl;
  cout << minItem->partType << endl;
  cout << "*******************" << endl;

  // Task 4
  // Remove from the wishList all the parts that are 'used'
  auto itr = remove_if(wishList.begin(), wishList.end(), [](const ComputerParts& c) {
    return c.used;
  });

  wishList.resize(itr - wishList.begin());
  //wishList.erase(itr, wishList.end());
  display(wishList);
  cout << "*******************" << endl;

  // Task 5
  // Find the average cost of all the parts in the wishList
  double sum = accumulate(wishList.begin(), wishList.end(), 0.0,
    [](const double& result, const ComputerParts& c) {
    return result + c.price;
  });

  cout << sum << endl;
  cout << sum / wishList.size() << endl;
  cout << "*******************" << endl;

  // Task 6
  // Change all the items in the wishList to 'used' and reduce their price by 20% and save this result to a new vector
  //vector<ComputerParts> res;
  //for_each(wishList.begin(), wishList.end(), [&res](ComputerParts c) { 
  //  if (!c.used) {
  //    c.used = true;
  //    c.price *= 0.8;
  //    res.push_back(c);
  //  }
  //});

  vector<ComputerParts> res(count_if(wishList.begin(), wishList.end(), 
    [](const ComputerParts& c) { return !c.used; }));
  transform(wishList.begin(), wishList.end(), res.begin(), [](ComputerParts c) {
    if (!c.used) {
      c.used = true;
      c.price *= 0.8;
    }
    return c;
  });
  display(res);
  cout << "*******************" << endl;
  display(wishList);
  cout << "*******************" << endl;

  // Task 7
  // Figure out how many of a given part type is in the wishList eg. how many GPUs and print to the screen
  string str = "GPU";
  auto cnt = count_if(wishList.begin(), wishList.end(), [str](const ComputerParts& c) {
    return c.partType == str;
  });

  cout << cnt << endl;
  cout << "*******************" << endl;


  // Task 8
  // Create new wishList of computer parts and combine it with the original one
  vector<ComputerParts> wl2;
  wl2.push_back(ComputerParts{"CPU", "AMD 7950X3D", 800, 200, false});
  wl2.push_back(ComputerParts{"GPU", "NVIDIA 3070", 500, 250, false});
  wl2.push_back(ComputerParts{"RAM", "Ripjaws 32GB", 120, 50, true});
  wl2.push_back(ComputerParts{"PSU", "Corsair SFX750", 200, 750, true});
  wl2.push_back(ComputerParts{"MB", "ASRock B550i", 150, 100, false});

  sort(wishList.begin(), wishList.end(), [](const ComputerParts& c1, const ComputerParts& c2) {
    return c1.price < c2.price;
  });
  sort(wl2.begin(), wl2.end(), [](const ComputerParts& c1, const ComputerParts& c2) {
    return c1.price < c2.price;
  });

  vector<ComputerParts> dest(wl2.size() + wishList.size());
  merge(wishList.begin(), wishList.end(), wl2.begin(), wl2.end(), dest.begin(),
    [](const ComputerParts& c1, const ComputerParts& c2) {
    return c1.price < c2.price;
  });

  display(dest);
  cout << "*******************" << endl;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            