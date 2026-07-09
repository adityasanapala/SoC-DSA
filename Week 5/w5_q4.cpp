#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        long long best = LLONG_MAX;
        for (long long m = 1; m <= 100000; m++) {
            long long cost = (m - 1) + (a + m - 1) / m + (b + m - 1) / m;
            best = min(best, cost);
        }
        printf("%lld\n", best);
    }
    return 0;
}
