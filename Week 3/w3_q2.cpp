#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if 't' products can be made in 'mid_time' seconds
bool can_produce(long long mid_time, const vector<long long>& k, long long t) {
    long long total_products = 0;
    for (long long machine_time : k) {
        total_products += (mid_time / machine_time);
        // Prevent overflow: if we already met or exceeded t, we can stop early
        if (total_products >= t) {
            return true;
        }
    }
    return total_products >= t;
}

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long t;
    if (!(cin >> n >> t)) return 0;

    vector<long long> k(n);
    long long min_machine_time = 1e9;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        min_machine_time = min(min_machine_time, k[i]);
    }

    // Binary search range boundaries
    long long low = 1;
    long long high = min_machine_time * t; // Safe upper bound based on the fastest machine
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (can_produce(mid, k, t)) {
            ans = mid;        // 'mid' is valid, record it as a potential answer
            high = mid - 1;   // Try to find a smaller valid time
        } else {
            low = mid + 1;    // 'mid' is too short, look for a larger time
        }
    }
    cout << ans << "\n";
    return 0;
}