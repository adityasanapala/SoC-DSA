#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {

        map<long long, int> pos;

        long long target = x - a[i];

        for (int j = i + 1; j < n; j++) {

            long long need = target - a[j];

            if (pos.count(need)) {
                cout << i + 1 << " "
                     << pos[need] + 1 << " "
                     << j + 1;
                return 0;
            }

            pos[a[j]] = j;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}