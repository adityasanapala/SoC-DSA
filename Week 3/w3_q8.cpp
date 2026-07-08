#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Max-priority queue to track the breaking points of our slope function
    priority_queue<long long> pq;
    long long min_steps = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        pq.push(x);
        
        // If the current element is smaller than the maximum seen so far,
        // it violates the non-decreasing condition.
        if (pq.top() > x) {
            min_steps += pq.top() - x; // Add the operational cost
            pq.pop();                  // Remove the outdated peak
            pq.push(x);                // Insert the new boundary point
        }
    }

    cout << min_steps << "\n";

    return 0;
}