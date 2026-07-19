#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long A[5005];
long long V[5005];
long long dp[5005];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        V[i] = A[i];
    }

    sort(V, V + n);

    for (int i = 0; i < n; i++) {
        long long prev = dp[0];
        
        for (int j = 0; j < n; j++) {
            if (dp[j] < prev) {
                prev = dp[j];
            }

            long long cur = abs(A[i] - V[j]);

            if (i == 0) {
                dp[j] = cur;
            } else {
                dp[j] = prev + cur;
            }
        }
    }

    long long ans = dp[0];
    for (int j = 1; j < n; j++) {
        if (dp[j] < ans) {
            ans = dp[j];
        }
    }

    cout << ans << "\n";
    return 0;
}