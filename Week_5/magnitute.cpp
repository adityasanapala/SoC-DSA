#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 998244353;
long long powerOfTwo(long long exp) {
    long long res = 1;
    long long base = 2;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> P(n);
    long long min_p = 0;
    long long current_sum = 0;
    for (int i = 0; i < n; i++) {
        current_sum += a[i];
        P[i] = current_sum;
        min_p = min(min_p, P[i]);
    }
    if (min_p >= 0) {
        cout << powerOfTwo(n) << "\n";
        return;
    }
    int non_neg_count = 0;
    long long total_ways = 0;
    for (int i = 0; i < n; i++) {
        if (P[i] == min_p) {
            long long exp = non_neg_count + (n - 1 - i);
            total_ways = (total_ways + powerOfTwo(exp)) % MOD;
        }
        if (P[i] >= 0) {
            non_neg_count++;
        }
    }
    cout << total_ways << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}