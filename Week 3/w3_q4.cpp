#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<int>;
using vpair = vector<pair<int, int>>;
string A, B;
int ans = 0;

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

int mymin(int a, int b, int c) { return min(a, min(b, c)); }

int fun(int a, int b) {
    // I will pass integers whcih represent the distance from the beginning.
    // but the string is changing
    // Nope it's not we are just adding 1 if there is a operation required
    // but never changing the string in place
    if (a < 0) { return b + 1; }
    if (b < 0) { return a + 1; }
    if (A[a] == B[b]) { return fun(a - 1, b - 1); }
    else { return 1 + mymin(fun(a - 1, b), fun(a, b - 1), fun(a - 1, b - 1)); }
    // here I am checking all three possibilities
    return 0;
}

int main() {
    cin >> A >> B;
    cout << fun(A.size() - 1, B.size() - 1) << endl;
}
