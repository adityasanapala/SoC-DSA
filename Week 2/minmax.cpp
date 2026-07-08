#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> pos(n + 1);

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            pos[x] = i;
        }

        int l = (n + 1) / 2;
        int r = l + (n % 2 == 0);

        int ans = n / 2;

while (
    l > 0 &&
    r <= n &&
    pos[l] < pos[r]
) {
    ans--;
    l--;
    r++;
}

        cout << ans << '\n';
    }

    return 0;
}