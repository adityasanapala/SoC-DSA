#include <iostream>
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
    int n, a;
    cin >> n;
    vint V(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        V[a] = i;
    }
    for (int i = 2; i <= n / 2; i++) {
        V[n / 3 + i] = n;
        // I need to swap 3 different the
        swap(V[2], V[n / 2 - 1 + i]);
        vprint(V);
    }
}
