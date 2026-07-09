#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    if (n >= m) {
        long long x;
        for (int i = 0; i < n; i++) scanf("%lld", &x);
        printf("YES\n");
        return 0;
    }

    vector<char> dp(m, 0);
    bool found = false;
    for (int i = 0; i < n; i++) {
        long long x;
        scanf("%lld", &x);
        if (found) continue;
        int r = (int)(x % m);
        vector<char> ndp = dp;
        ndp[r] = 1;
        for (int s = 0; s < m; s++)
            if (dp[s]) ndp[(s + r) % m] = 1;
        dp.swap(ndp);
        if (dp[0]) found = true;
    }
    printf(found ? "YES\n" : "NO\n");
    return 0;
}
