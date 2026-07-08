#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long t;
    cin >> n >> t;

    vector<long long> k(n);

    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    long long l = 1;
    long long r = 1e18;
    long long ans = r;

    while (l <= r) {
        long long mid = l + (r - l) / 2;

        long long products = 0;

        for (int i = 0; i < n; i++) {
            products += mid / k[i];

            if (products >= t) {
                break;
            }
        }

        if (products >= t) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
