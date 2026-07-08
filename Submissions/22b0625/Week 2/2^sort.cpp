#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> good(n - 1);

        for (int i = 0; i < n - 1; i++) {
            good[i] = (a[i] < 2 * a[i + 1]);
        }

        int cur = 0;

        for (int i = 0; i < k; i++) {
            cur += good[i];
        }

        int ans = (cur == k);

        for (int i = k; i < n - 1; i++) {
            cur += good[i];
            cur -= good[i - k];

            if (cur == k) {
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}