#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<int>;

template <typename T>
void vprint(T& V) {
    for (auto& i : V) { cout << i << " "; }
    cout << "\n";
}

template <typename T>
void pprint(T& P) {
    for (auto& i : P) { cout << i.first << " " << i.second << "\n"; }
    cout << "\n";
}

int main() {
    multiset<int> ms = {5, 3, 3, 1};

    // Finding an element (3)
    vprint(ms);
    auto it = ms.find(3);
    if (it != ms.end()) ms.erase(it);
    vprint(ms);
    return 0;
}
