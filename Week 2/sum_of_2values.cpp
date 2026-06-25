#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    long long x;
    cin >> n >> x;

    unordered_map<long long, int> mp;

    for (int i = 1; i <= n; i++) {

        long long num;
        cin >> num;

        long long need = x - num;

        if (mp.count(need)) {
            cout << mp[need] << " " << i;
            return 0;
        }

        mp[num] = i;
    }

    cout << "IMPOSSIBLE";

    return 0;
}