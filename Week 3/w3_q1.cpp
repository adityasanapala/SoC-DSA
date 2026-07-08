#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> durations(n);
    long long total_reward = 0;

    for (int i = 0; i < n; i++) {
        int a, d;
        cin >> a >> d;
        durations[i] = a;
        total_reward += d; // Add the deadline component directly
    }

    // Sort durations in ascending order to minimize finishing times
    sort(durations.begin(), durations.end());

    long long current_time = 0;
    for (int i = 0; i < n; i++) {
        current_time += durations[i];
        total_reward -= current_time; // Subtract the finishing time component
    }

    cout << total_reward << "\n";

    return 0;
}