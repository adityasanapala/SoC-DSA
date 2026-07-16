  #include <iostream>
  #include <map>
  #include <algorithm>
  #include <map>
  #include <vector>
  #include <set>
using namespace std;

const int MOD = 1e9 + 7;



    int n;
    if (!(cin >> n)) return 0;

    // dp[i] will store the number of ways to make sum i
    vector<long long> dp(n + 1, 0);


    dp[0] = 1;

    // Build the DP table iteratively
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    cout << dp[n] << "\n";

    return 0;
}
