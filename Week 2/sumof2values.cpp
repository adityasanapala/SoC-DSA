#include <iostream>
#include <map>
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
    int n, tgt;
    cin >> n >> tgt;
    map<int, int> M;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        M[a] = i;
    }
    pprint(M);
    auto l = M.begin();
    auto r = M.end() - 1;
    // printf("r->first:%i, r->second:%i\n", r->first, r->second);
    while (r != l) {
        printf("l->first:%i, r->first:%i\n", l->first, r->first);
        if (l->first + r->first == tgt) {
            cout << l->second << " " << r->second << endl;
            r--;
        }
        else if (l->first + r->first > tgt) { r--; }
        else if (l->first + r->first < tgt) { l++; }
    }
}
// I am just so cooked
