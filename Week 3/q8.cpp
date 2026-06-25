#include <iostream>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long a[n];
    long long b[n];
    long long dp0[n];
    long long dp1[n];
    long long pref[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    int M = unique(b, b + n) - b;

    for (int j = 0; j < M; j++) {
        dp0[j] = llabs(a[0] - b[j]);
    }

    for (int i = 1; i < n; i++) {
        pref[0] = dp0[0];
        for (int j = 1; j < M; j++) {
            pref[j] = min(pref[j - 1], dp0[j]);
        }

        for (int j = 0; j < M; j++) {
            dp1[j] = pref[j] + llabs(a[i] - b[j]);
        }

        for (int j = 0; j < M; j++) {
            dp0[j] = dp1[j];
        }
    }

    long long ans = dp0[0];
    for (int j = 1; j < M; j++) {
        ans = min(ans, dp0[j]);
    }

    cout << ans << "\n";
    return 0;
}