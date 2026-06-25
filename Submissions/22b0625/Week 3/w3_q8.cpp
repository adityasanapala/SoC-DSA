
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

long long solve(vector<long long> a) {
    int n = a.size();

    vector<long long> vals = a;
    sort(vals.begin(), vals.end());

    vector<long long> prev(n), cur(n);

    for (int j = 0; j < n; j++) {
        prev[j] = llabs(a[0] - vals[j]);
    }

    for (int i = 1; i < n; i++) {
        long long pref = prev[0];
        
        for (int j = 0; j < n; j++) {
            pref = min(pref, prev[j]);
            cur[j] = pref + llabs(a[i] - vals[j]);
        }

        swap(prev, cur);
    }

    return *min_element(prev.begin(), prev.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = solve(a);

    reverse(a.begin(), a.end());
    ans = min(ans, solve(a));

    cout << ans << '\n';

    return 0;
}