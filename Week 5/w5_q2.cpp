#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 998244353;
const int N = 200005;

ll mx[N], mn[N];
int waysMx[N], waysMn[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        mx[0] = mn[0] = 0;
        waysMx[0] = waysMn[0] = 1;

        for (int i = 1; i <= n; i++) {
            ll a;
            cin >> a;

            ll c1 = mx[i - 1] + a;
            ll c2 = llabs(mx[i - 1] + a);
            ll c3 = mn[i - 1] + a;
            ll c4 = llabs(mn[i - 1] + a);

            mx[i] = max({c1, c2, c3, c4});
            mn[i] = min({c1, c2, c3, c4});

            waysMx[i] = 0;
            waysMn[i] = 0;

            auto addMx = [&](int v) {
                waysMx[i] += v;
                if (waysMx[i] >= MOD) waysMx[i] -= MOD;
            };

            auto addMn = [&](int v) {
                waysMn[i] += v;
                if (waysMn[i] >= MOD) waysMn[i] -= MOD;
            };

            if (mx[i] == c1) addMx(waysMx[i - 1]);
            if (mx[i] == c2) addMx(waysMx[i - 1]);

            if (mn[i] == c1) addMn(waysMx[i - 1]);
            if (mn[i] == c2) addMn(waysMx[i - 1]);

            // avoid counting the same state twice
            if (mx[i - 1] != mn[i - 1]) {
                if (mx[i] == c3) addMx(waysMn[i - 1]);
                if (mx[i] == c4) addMx(waysMn[i - 1]);

                if (mn[i] == c3) addMn(waysMn[i - 1]);
                if (mn[i] == c4) addMn(waysMn[i - 1]);
            }
        }

        cout << waysMx[n] << '\n';
    }

    return 0;
}