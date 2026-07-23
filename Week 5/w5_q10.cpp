#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

bool checkOdd(int x) {
    int cnt = 0;

    for (int v : a) {
        if (cnt % 2 == 0) {
            if (v <= x)
                cnt++;
        } else {
            cnt++;
        }
    }

    return cnt >= k;
}

bool checkEven(int x) {
    int cnt = 0;

    for (int v : a) {
        if (cnt % 2 == 0) {
            cnt++;
        } else {
            if (v <= x)
                cnt++;
        }
    }

    return cnt >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    a.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int lo = 1, hi = 1e9, ans = 1e9;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (checkOdd(mid) || checkEven(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
}