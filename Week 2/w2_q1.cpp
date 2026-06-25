#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> k(n);
    for (int i = 0; i < n;i++){
        cin >> k[i];
    }
    int max_len = 0;
    int len = 0;
    int si = 0; // start index
    // unordered_map<int, int> m;
    /*when the difference between every single number is exactly 172933,
     time for linear scan per element becomes O(n) instead of O(1)
     this is called ANTI-HASH test */
    map<int, int> m;
    for (int i = 0; i < n;i++){
        auto it = m.find(k[i]);
        if (it != m.end() && it->second >= si){
            si = it->second + 1;
        }
        m[k[i]]=i;
        max_len = max(max_len, i - si + 1);
    }
    cout << max_len << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}