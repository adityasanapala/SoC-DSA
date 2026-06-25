#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    int n;
    cin >> x >> n;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        pq.push(a);
    }

    long long ans = 0;

    while (pq.size() > 1) {
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        ans += a + b;
        pq.push(a + b);
    }

    cout << ans;
}