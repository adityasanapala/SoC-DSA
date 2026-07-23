#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long ans = a + b;
        for (long long m = 1; m <= 100000; m++) {
            long long moves = (m - 1) + (a + m - 1) / m + (b + m - 1) / m;
            ans = min(ans, moves);
        }
        cout << ans << "\n";
    }
    return 0;
}