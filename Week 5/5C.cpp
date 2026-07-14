#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> freqs;
    int current_freq = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i-1]) {
            current_freq++;
        } else {
            freqs.push_back(current_freq);
            current_freq = 1;
        }
    }
    freqs.push_back(current_freq);
    
    sort(freqs.begin(), freqs.end());
    
    int m = freqs.size();
    vector<long long> suf_sum(m + 1, 0);
    for (int i = m - 1; i >= 0; --i) {
        suf_sum[i] = suf_sum[i+1] + freqs[i];
    }
    
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (i > 0 && freqs[i] == freqs[i-1]) {
            continue;
        }
        
        long long sz = m - i;
        long long sum = suf_sum[i];
        
        long long rem = k - sum;
        if (rem % sz == 0) {
            long long delta = rem / sz;
            if (freqs[i] + delta >= 1) {
                ans++;
            }
        }
    }
    
    cout << ans << "\n";
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}