#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<long long> a(n);
    for (auto &x : a) scanf("%lld", &x);

    long long ans = 0;
    int cur = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] < 2 * a[i + 1]) cur++;
        else cur = 0;
        if (cur >= k) ans++;
    }
    printf("%lld\n", ans);
    return 0;
}
