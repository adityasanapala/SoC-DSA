#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> pos(n + 1);

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            pos[x] = i;
        }

        int l = 1;
        int r = n;

        while (l < r &&
               pos[l] < pos[l + 1] &&
               pos[r - 1] < pos[r] &&
               pos[l] < pos[r]) {
            l++;
            r--;
        }

        cout << (r - l + 1) / 2 << "\n";
    }
}