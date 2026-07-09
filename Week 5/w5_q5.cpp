#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

        long long lo = max(1LL, n - 200);
        long long best = LLONG_MIN;
        for (long long i = lo; i <= n; i++) {
            for (long long j = i + 1; j <= n; j++) {
                long long v = i * j - k * (a[i] | a[j]);
                best = max(best, v);
            }
        }
        printf("%lld\n", best);
    }
    return 0;
}
