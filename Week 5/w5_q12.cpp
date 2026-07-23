#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Fibonacci numbers
    vector<ll> fib = {1, 1};
    while (fib.back() <= 1000000000LL)
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);

    // Prefix sums
    vector<ll> pref(fib.size());
    pref[0] = fib[0];
    for (int i = 1; i < (int)fib.size(); i++)
        pref[i] = pref[i - 1] + fib[i];

    int T;
    cin >> T;

    while (T--) {
        int k;
        cin >> k;

        vector<ll> cnt(k);
        ll sum = 0;

        priority_queue<pair<ll,int>> pq;

        for (int i = 0; i < k; i++) {
            cin >> cnt[i];
            sum += cnt[i];
            pq.push({cnt[i], i});
        }

        int m = lower_bound(pref.begin(), pref.end(), sum) - pref.begin();

        if (m == (int)pref.size() || pref[m] != sum) {
            cout << "NO\n";
            continue;
        }

        bool ok = true;
        int last = -1;

        for (int i = m; i >= 0; i--) {

            if (pq.empty()) {
                ok = false;
                break;
            }

            auto first = pq.top();
            pq.pop();

            pair<ll,int> second = {-1,-1};
            bool usedSecond = false;

            if (first.second == last) {
                if (pq.empty()) {
                    ok = false;
                    break;
                }
                second = pq.top();
                pq.pop();
                usedSecond = true;
            }

            pair<ll,int> cur = usedSecond ? second : first;

            if (cur.first < fib[i]) {
                ok = false;
                break;
            }

            cur.first -= fib[i];
            last = cur.second;

            if (cur.first > 0)
                pq.push(cur);

            if (usedSecond)
                pq.push(first);
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}