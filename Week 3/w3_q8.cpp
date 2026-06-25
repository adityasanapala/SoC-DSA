#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<long long> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.begin(), b.end());

    const long long INF = 1e18;

    vector<long long> prev(n), curr(n);

    // First element
    for (int j = 0; j < n; j++)
        prev[j] = abs(a[0] - b[j]);

    // Remaining elements
    for (int i = 1; i < n; i++) {

        long long best = INF;

        for (int j = 0; j < n; j++) {

            best = min(best, prev[j]);

            curr[j] = best + abs(a[i] - b[j]);
        }

        prev = curr;
    }

    cout << *min_element(prev.begin(), prev.end());

    return 0;
}