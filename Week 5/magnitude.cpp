#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const long long INF = 1e17;

void solve() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> dp = {{0, 1}};
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        long long nmin = INF;
        long long nmax = -INF;
        
        for (auto p : dp) {
            long long v1 = p.first + x;
            long long v2 = (v1 < 0 ? -v1 : v1);
            nmin = min({nmin, v1, v2});
            nmax = max({nmax, v1, v2});
        }
        
        long long wmin = 0;
        long long wmax = 0;
        
        for (auto p : dp) {
            long long v = p.first;
            long long w = p.second;
            long long v1 = v + x;
            long long v2 = (v1 < 0 ? -v1 : v1);
            
            if (v1 == nmin) wmin = (wmin + w) % MOD;
            if (v2 == nmin) wmin = (wmin + w) % MOD;
            
            if (nmin != nmax) {
                if (v1 == nmax) wmax = (wmax + w) % MOD;
                if (v2 == nmax) wmax = (wmax + w) % MOD;
            }
        }
        
        dp.clear();
        dp.push_back({nmin, wmin});
        if (nmin != nmax) {
            dp.push_back({nmax, wmax});
        }
    }
    
    if (dp.size() == 2) {
        cout << dp[1].second << "\n";
    } else {
        cout << dp[0].second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}