#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    long long x;

    cin >> n >> x;

    vector<long long> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<long long, pair<int, int>> mp;

    for (int i = 1; i <= n; i++) {

        for (int j = i + 1; j <= n; j++) {

            long long need = x - a[i] - a[j];

            if (mp.find(need) != mp.end()) {

                int p = mp[need].first;
                int q = mp[need].second;

                if (p != i && p != j &&
                    q != i && q != j) {

                    cout << p << " " << q << " " << i << " " << j << '\n';

                    return 0;
                }
            }
        }

        for (int j = 1; j < i; j++) {

            long long sum = a[i] + a[j];

            mp[sum] = {j, i};
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}