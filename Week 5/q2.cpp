#include <iostream>
using namespace std;

using int64 = long long;
const int MOD = 998244353;

int main() {

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int64 mn = 0, mx = 0;
        int cmn = 1, cmx = 1;

        for (int i = 0; i < n; i++) {
            int64 x;
            cin >> x;

            int64 nmn = mn + x;
            int ncmn = (mn + x >= 0 ? (2LL * cmn) % MOD : cmn);

            int64 v1 = llabs(mn + x);
            int64 v2 = llabs(mx + x);
            int64 nmx = max(v1, v2);

            int ncmx = 0;

            if (v1 > v2) {
                ncmx = (mn + x >= 0 ? (2LL * cmn) % MOD : cmn);
            } else if (v2 > v1) {
                ncmx = (mx + x >= 0 ? (2LL * cmx) % MOD : cmx);
            } else {
                if (mn == mx) {
                    ncmx = (mn + x >= 0 ? (2LL * cmn) % MOD : cmn);
                } else {
                    ncmx = 0;
                    ncmx += (mn + x >= 0 ? (2LL * cmn) % MOD : cmn);
                    if (ncmx >= MOD) ncmx -= MOD;
                    ncmx += (mx + x >= 0 ? (2LL * cmx) % MOD : cmx);
                    if (ncmx >= MOD) ncmx -= MOD;
                }
            }

            mn = nmn;
            mx = nmx;
            cmn = ncmn;
            cmx = ncmx;
        }

        cout << cmx << '\n';
    }

    return 0;
}