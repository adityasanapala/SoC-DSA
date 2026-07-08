#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, t;
    cin >> n >> t;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long low = 1;
    long long high = (*min_element(a.begin(), a.end())) * t;
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        long long products = 0;

        for (int i = 0; i < n; i++) {
            products += mid / a[i];

            if (products >= t)
                break;
        }

        if (products >= t) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << ans;

    return 0;
}