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
            int sum = a + V[l].first + V[r].first;
            // if (sum == tgt && V[l].second != i && V[r].second != i) {
            if (sum == tgt) {
                cout << i << " " << V[l].second << " " << V[r].second << endl;
                return 0;
            }
            else if (sum < tgt) { l + 1 == i ? l += 2 : l++; }
            else if (sum > tgt) { r - 1 == i ? r -= 2 : r--; }
            // else if (sum < tgt) { l++; }
            // else if (sum > tgt) { r--; }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
// I use arch btw
// why am I getting this even if I have done so
