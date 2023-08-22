#include <iostream>
using namespace std;
struct temp {
    std::string name{};
    temp() {
        name = "Name";
    }
    temp(std::string s) {
        name = s;
    }
};
template <typename T>
class fruit {
    static T val; // class member
public:
    fruit() {
        //...
    }
    static T retVal() { // class function
        return val;
    }
};
template<typename T>
T fruit<T>::val{};
template<>
temp fruit<temp>::val = temp("Stuff");

int main() {
    fruit<temp> f;
    cout << f.retVal().name << endl;
}