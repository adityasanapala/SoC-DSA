#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    priority_queue<long long> pq;
    long long cost = 0;
    for (int i = 0; i < n; i++) {
        long long a;
        scanf("%lld", &a);
        pq.push(a);
        if (pq.top() > a) {
            cost += pq.top() - a;
            pq.pop();
            pq.push(a);
        }
    }
    printf("%lld\n", cost);
    return 0;
}
