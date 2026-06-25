#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    if (!(cin >> s1 >> s2)) return 0;

    int n = s1.length();
    int m = s2.length();

    // Create a 2D DP table initialized to 0
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize base cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i; // Deleting all characters from s1
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j; // Inserting all characters into s1 to match s2
    }

    // Populate the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({
                    dp[i - 1][j - 1], // Replace
                    dp[i - 1][j],     // Remove
                    dp[i][j - 1]      // Add
                });
            }
        }
    }

    // The answer is the edit distance between the full lengths of both strings
    cout << dp[n][m] << "\n";

    return 0;
}