#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long, int>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {

        long long need = x - a[i].first;

        int l = i + 1;
        int r = n - 1;

        while (l < r) {

            long long sum = a[l].first + a[r].first;

            if (sum == need) {
                cout << a[i].second << " " << a[l].second << " " << a[r].second;
                return 0;
            }

            if (sum < need) {
                l++;
            }
            else {
                r--;
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}