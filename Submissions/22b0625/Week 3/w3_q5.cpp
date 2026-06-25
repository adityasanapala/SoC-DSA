
#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;
const int MAXN = 1000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> dp0(MAXN + 1);
    vector<long long> dp1(MAXN + 1);

    dp0[1] = 1;
    dp1[1] = 1;

    for (int i = 2; i <= MAXN; i++) {
        dp0[i] = (4 * dp0[i - 1] + dp1[i - 1]) % MOD;
        dp1[i] = (dp0[i - 1] + 2 * dp1[i - 1]) % MOD;
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cout << (dp0[n] + dp1[n]) % MOD << '\n';
    }

    return 0;
}