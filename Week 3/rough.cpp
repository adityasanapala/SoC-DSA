#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<int>;
using vpair = vector<pair<int, int>>;

template <typename T>
void vprint(const T& v) {
    for (const auto& i : v) { cout << i << " "; }
    cout << "\n";
}

template <typename T>
void pprint(const T& v) {
    for (const auto& i : v) { cout << i.first << " " << i.second << "\n"; }
    cout << "\n";
}

int main() {
    string str = "aks";
    cout << str << endl;
    for (int i = 0; str[i] != '\0'; i++) { cout << str[i] << endl; }
}
// the end of a string(which is basically an array) is a null
