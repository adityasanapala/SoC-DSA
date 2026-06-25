#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);

    unordered_map<long long, int> mp;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        long long need = x - a[i];

        if (mp.count(need)) {
            cout << mp[need] + 1 << " " << i + 1;
            return 0;
        }

        mp[a[i]] = i;
    }

    cout << "IMPOSSIBLE";
}