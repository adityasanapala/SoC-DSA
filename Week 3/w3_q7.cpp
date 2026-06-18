#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    int n;
    scanf("%lld %d", &x, &n);
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++) {
        long long p;
        scanf("%lld", &p);
        pq.push(p);
    }

    long long cost = 0;
    while (pq.size() > 1) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        cost += a + b;
        pq.push(a + b);
    }
    printf("%lld\n", cost);
    return 0;
}
