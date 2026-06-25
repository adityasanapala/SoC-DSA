#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    const int m = 1e9 + 7;
    vector<int> solve(n+1);
    solve[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int die = 1; die <= 6; die++) {
            if (i - die >= 0) {
                solve[i] = (solve[i] + solve[i - die]) % m;
            }
        }
    }
    cout << solve[n] << "\n";
    return 0;
}