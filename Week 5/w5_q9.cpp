#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> two(n + 1, vector<int>(n + 1));
    vector<vector<int>> five(n + 1, vector<int>(n + 1));

    int zx = -1, zy = -1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;

            if (x == 0) {
                zx = i;
                zy = j;
                two[i][j] = five[i][j] = 1;
                continue;
            }

            int t = 0, f = 0;

            int y = x;
            while (y % 2 == 0) {
                t++;
                y /= 2;
            }

            y = x;
            while (y % 5 == 0) {
                f++;
                y /= 5;
            }

            two[i][j] = t;
            five[i][j] = f;
        }
    }

    vector<vector<int>> dp2(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> dp5(n + 1, vector<int>(n + 1, INF));

    vector<vector<char>> par2(n + 1, vector<char>(n + 1));
    vector<vector<char>> par5(n + 1, vector<char>(n + 1));

    dp2[1][1] = two[1][1];
    dp5[1][1] = five[1][1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            if (i == 1 && j == 1) continue;

            if (i > 1 && dp2[i - 1][j] + two[i][j] < dp2[i][j]) {
                dp2[i][j] = dp2[i - 1][j] + two[i][j];
                par2[i][j] = 'D';
            }

            if (j > 1 && dp2[i][j - 1] + two[i][j] < dp2[i][j]) {
                dp2[i][j] = dp2[i][j - 1] + two[i][j];
                par2[i][j] = 'R';
            }

            if (i > 1 && dp5[i - 1][j] + five[i][j] < dp5[i][j]) {
                dp5[i][j] = dp5[i - 1][j] + five[i][j];
                par5[i][j] = 'D';
            }

            if (j > 1 && dp5[i][j - 1] + five[i][j] < dp5[i][j]) {
                dp5[i][j] = dp5[i][j - 1] + five[i][j];
                par5[i][j] = 'R';
            }
        }
    }

    int best = min(dp2[n][n], dp5[n][n]);

    if (zx != -1 && best > 1) {
        cout << 1 << "\n";

        for (int i = 1; i < zx; i++) cout << 'D';
        for (int j = 1; j < zy; j++) cout << 'R';
        for (int i = zx; i < n; i++) cout << 'D';
        for (int j = zy; j < n; j++) cout << 'R';

        cout << "\n";
        return 0;
    }

    cout << best << "\n";

    string path;

    int i = n, j = n;

    if (dp2[n][n] < dp5[n][n]) {
        while (i != 1 || j != 1) {
            char c = par2[i][j];
            path += c;
            if (c == 'D') i--;
            else j--;
        }
    } else {
        while (i != 1 || j != 1) {
            char c = par5[i][j];
            path += c;
            if (c == 'D') i--;
            else j--;
        }
    }

    reverse(path.begin(), path.end());

    cout << path << "\n";
}