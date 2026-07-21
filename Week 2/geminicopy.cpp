#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        pos[x] = i;  // Store 1-based position of element x
    }
    int l = (n + 1) / 2;
    int r = (n / 2) + 1;
    // Check if the middle elements are in correct relative order
    while (l > 0 && r <= n) {
        if (l == r) {
            // For odd n, middle element alone is always fine
            l--;
            r++;
            continue;
        }
        if (pos[l] < pos[l + 1] && pos[r - 1] < pos[r]) {
            l--;
            r++;
        }
        else { break; }
    }
    // l is the number of pairs outside the valid contiguous range
    cout << l << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
