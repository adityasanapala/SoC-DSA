#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string a, b;
        cin >> a >> b;

        int n = a.size();
        int m = b.size();

        vector<vector<int>> valueA(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            valueA[i][i] = a[i] - '0';
            for (int j = i + 1; j < n; j++)
                valueA[i][j] = (valueA[i][j - 1] + (a[j] - '0')) % 10;
        }

        vector<vector<int>> valueB(m, vector<int>(m));
        for (int i = 0; i < m; i++) {
            valueB[i][i] = b[i] - '0';
            for (int j = i + 1; j < m; j++)
                valueB[i][j] = (valueB[i][j - 1] + (b[j] - '0')) % 10;
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                for (int x = 0; x < i; x++) {
                    for (int y = 0; y < j; y++) {

                        if (dp[x][y] == -1) continue;

                        if (valueA[x][i - 1] == valueB[y][j - 1]) {
                            dp[i][j] = max(dp[i][j], dp[x][y] + 1);
                        }
                    }
                }

            }
        }

        cout << dp[n][m] << "\n";
    }

    return 0;
}