#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;

const int MOD = 998244353;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n + 1);
        vector<ll> minimumValue(n + 1);
        vector<ll> maximumValue(n + 1);

        vector<ll> waysMinimum(n + 1);
        vector<ll> waysMaximum(n + 1);

        minimumValue[0] = 0;
        maximumValue[0] = 0;
        waysMinimum[0] = 1;
        waysMaximum[0] = 1;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];

            minimumValue[i] = minimumValue[i - 1] + a[i];

            ll valueFromMinimum = abs(minimumValue[i - 1] + a[i]);
            ll valueFromMaximum = abs(maximumValue[i - 1] + a[i]);

            maximumValue[i] = max(valueFromMinimum, valueFromMaximum);

            waysMinimum[i] = waysMinimum[i - 1];
            if (minimumValue[i - 1] + a[i] >= 0) {
                waysMinimum[i] += waysMinimum[i - 1];
                waysMinimum[i] %= MOD;
            }

            if (valueFromMaximum > valueFromMinimum) {
                waysMaximum[i] = waysMaximum[i - 1];

                if (maximumValue[i - 1] + a[i] >= 0) {
                    waysMaximum[i] += waysMaximum[i - 1];
                    waysMaximum[i] %= MOD;
                }
            }
            else if (valueFromMaximum < valueFromMinimum) {
                waysMaximum[i] = waysMinimum[i - 1];

                if (minimumValue[i - 1] + a[i] >= 0) {
                    waysMaximum[i] += waysMinimum[i - 1];
                    waysMaximum[i] %= MOD;
                }
            }
            else {
                if (minimumValue[i - 1] == maximumValue[i - 1]) {
                    waysMaximum[i] = waysMinimum[i - 1];

                    if (minimumValue[i - 1] + a[i] >= 0) {
                        waysMaximum[i] += waysMinimum[i - 1];
                        waysMaximum[i] %= MOD;
                    }
                }
                else {
                    waysMaximum[i] = 0;

                    waysMaximum[i] += waysMinimum[i - 1];
                    if (minimumValue[i - 1] + a[i] >= 0) {
                        waysMaximum[i] += waysMinimum[i - 1];
                    }

                    waysMaximum[i] %= MOD;

                    waysMaximum[i] += waysMaximum[i - 1];
                    if (maximumValue[i - 1] + a[i] >= 0) {
                        waysMaximum[i] += waysMaximum[i - 1];
                    }

                    waysMaximum[i] %= MOD;
                }
            }
        }

        cout << waysMaximum[n] << endl;
    }

    return 0;
}