#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    long long a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long max1 = -1e18; 
    
    int st = max(1, n - 2 * (int)k); 

    for (int i = st; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            long long cur = (long long)i * j - k * (a[i] | a[j]);
            if (cur > max1) {
                max1 = cur;
            }
        }
    }

    cout << max1 << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}