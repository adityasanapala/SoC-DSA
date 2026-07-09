#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<long long, long long>> t(n);
    for (int i = 0; i < n; i++) scanf("%lld %lld", &t[i].first, &t[i].second);
    sort(t.begin(), t.end());

    long long cur = 0, ans = 0;
    for (auto &p : t) {
        cur += p.first;
        ans += p.second - cur;
    }
    printf("%lld\n", ans);
    return 0;
}
