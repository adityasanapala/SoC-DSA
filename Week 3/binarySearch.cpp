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

int bins(const vint& V, int tgt) {
    int end = V.size() - 1, st = 0;
    int mid;
    while (end >= st) {
        mid = (st + end) / 2;
        if (V[mid] == tgt) { return mid; }
        else if (V[mid] > tgt) { end = mid - 1; }
        else { st = mid + 1; }
    }
    return -1;
}

int main() {
    vint V = {0, 1, 2, 3, 4, 5, 6};
    cout << bins(V, 4) << endl;
}
