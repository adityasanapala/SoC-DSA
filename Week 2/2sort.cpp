#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int consecutive_valid_pairs = 0;
    int ans = 0;

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] < 2 * a[i + 1]) {
            consecutive_valid_pairs++;
        } else {
            consecutive_valid_pairs = 0;
        }

        if (consecutive_valid_pairs >= k) {
            ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}