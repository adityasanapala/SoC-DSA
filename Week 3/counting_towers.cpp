#include <bits/stdc++.h>
using namespace std;
const int n = 1e6;
const int m = 1e9 + 7;
long long dp[n + 1][2];// keep this out main to not cause stack overflow

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = (4 * dp[i - 1][0] + dp[i - 1][1]) % m;
        dp[i][1] = (dp[i - 1][0] + 2 * dp[i - 1][1]) % m;
    }    
    int t;
    cin >> t;
    while(t--){
        int c;
        cin >> c;
        long long total_ways = (dp[c][0] + dp[c][1]) % m;
        cout << total_ways << "\n";
    }
    return 0;
}
//main should always return int so dont try any other thing