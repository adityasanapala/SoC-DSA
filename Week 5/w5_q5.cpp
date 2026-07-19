#include <iostream>

using namespace std;

void solve() {
    long long n, c;
    cin >> n >> c;

    long long s[n];
    long long eve = 0;
    long long odd = 0;

    long long tot = (c + 1) * (c + 2) / 2;
    long long sum = 0;
    long long diff = 0;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i] % 2 == 0) {
            eve++;
        } else {
            odd++;
        }

        sum += (s[i] / 2) + 1;
        diff += (c - s[i]) + 1;
    }

    long long qwer = (eve * (eve + 1) / 2) + (odd * (odd + 1) / 2);

    long long ans = tot - sum - diff + qwer;
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}