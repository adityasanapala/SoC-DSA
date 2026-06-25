#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, P1, P2, P3, T1, T2;
    cin >> n >> P1 >> P2 >> P3 >> T1 >> T2;

    vector<long long> l(n), r(n);

    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {


        ans += (r[i] - l[i]) * P1;

        if (i == n - 1)
            continue;

        long long gap = l[i + 1] - r[i];

        if (gap <= T1) {

            ans += gap * P1;

        }
        else if (gap <= T1 + T2) {

            ans += T1 * P1;
            ans += (gap - T1) * P2;

        }
        else {

            ans += T1 * P1;
            ans += T2 * P2;
            ans += (gap - T1 - T2) * P3;

        }
    }

    cout << ans << '\n';

    return 0;
}