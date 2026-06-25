#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        pos[val] = i;
    }

    int l = (n + 1) / 2;
    int r = (n + 2) / 2;

    while (l >= 1 && r <= n) {
        if (l == r) {
            l--;
            r++;
            continue;
        }
        if (pos[l] < pos[l + 1] && pos[r] > pos[r - 1]) {
            l--;
            r++;
        } else {
            break;
        }
    }

    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}