#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    long long x;
    int n;
    cin >> x >> n;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; ++i) {
        long long d;
        cin >> d;
        pq.push(d);
    }

    long long cost = 0;

    while (pq.size() > 1) {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();

        long long cur = first + second;
        cost += cur;

        pq.push(cur);
    }

    cout << cost << "\n";

    return 0;
}