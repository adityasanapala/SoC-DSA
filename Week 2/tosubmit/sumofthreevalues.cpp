#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<int>;
int n, tgt;

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
    cin >> n >> tgt;
    vector<pair<int, int>> V(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> V[i].first;
        V[i].second = i;
    }
    sort(V.begin(), V.end());
    for (int i = 1; i <= n; i++) {
        int a = V[i].first;
        int l = 1, r = n;
        while (l < r) {
            if (r == i) { r--; }
            else if (l == i) { l++; }
            if (l == r) { break; }
            int sum = a + V[l].first + V[r].first;
            if (sum == tgt) {
                cout << V[i].second << " " << V[l].second << " " << V[r].second << endl;
                return 0;
            }
            else if (sum < tgt) { l++; }
            else if (sum > tgt) { r--; }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
// I use arch btw
// why am I getting this even if I have done so
