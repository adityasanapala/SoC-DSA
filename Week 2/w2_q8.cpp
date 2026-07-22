#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int cnt[1000005];

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int l = 0, distinct_count = 0;
    int max_len = 0;
    int best_l = 1, best_r = 1;
    for (int r = 0; r < n; r++) {
        if (cnt[a[r]] == 0) {
            distinct_count++;
        }
        cnt[a[r]]++;
        while (distinct_count > k) {
            cnt[a[l]]--;
            if (cnt[a[l]] == 0) {
                distinct_count--;
            }
            l++;
        }
        int curr_len = r - l + 1;
        if (curr_len > max_len) {
            max_len = curr_len;
            best_l = l + 1;
            best_r = r + 1;
        }
    }
    cout << best_l << " " << best_r << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
