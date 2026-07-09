#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MX = 1e6 + 1;

int main() {
    vector<long long> sep(MX), joi(MX);
    sep[1] = 1;
    joi[1] = 1;
    for (int i = 2; i < MX; i++) {
        sep[i] = (4 * sep[i - 1] + 2 * joi[i - 1]) % MOD;
        joi[i] = (sep[i - 1] + joi[i - 1]) % MOD;
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", (sep[n] + joi[n]) % MOD);
    }
    return 0;
}
