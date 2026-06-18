#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, t;
    scanf("%lld %lld", &n, &t);
    vector<long long> k(n);
    for (auto &x : k) scanf("%lld", &x);

    long long lo = 1, hi = (long long)2e18;
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2, made = 0;
        for (auto x : k) {
            made += mid / x;
            if (made >= t) break;
        }
        if (made >= t) hi = mid;
        else lo = mid + 1;
    }
    printf("%lld\n", lo);
    return 0;
}
