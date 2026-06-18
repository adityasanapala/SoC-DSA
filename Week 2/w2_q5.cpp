#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<long long> a(n);
    for (auto &x : a) scanf("%lld", &x);

    sort(a.begin(), a.end());
    long long m = a[n / 2], cost = 0;
    for (auto x : a) cost += llabs(x - m);
    printf("%lld\n", cost);
    return 0;
}
