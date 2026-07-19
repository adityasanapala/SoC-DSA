#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n >= m) {
        cout << "YES\n";
        return 0;
    }

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
    }

    bool dp[m];
    bool qwer[m];
    for (int i = 0; i < m; i++) {
        dp[i] = false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            qwer[j] = dp[j];
        }

        qwer[a[i]] = true;

        for (int j = 0; j < m; j++) {
            if (dp[j]) {
                qwer[(j + a[i]) % m] = true;
            }
        }

        for (int j = 0; j < m; j++) {
            dp[j] = qwer[j];
        }

        if (dp[0]) {
            cout << "YES\n";
            return 0;
        }
    }

    if (dp[0]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}