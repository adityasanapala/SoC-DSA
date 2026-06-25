#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fo(i,n) for(int i=0;i<n;i++)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, sum;
    cin >> n >> sum;   
    vector<ll> b(n);
    fo(i, n) {
        cin >> b[i];
    }
    map<ll, ll> a;
    fo(i, n) {
        for (int j = i + 1; j < n; j++) {
            ll complement = sum - b[i] - b[j];
            
            auto find_it = a.find(complement);
            if (find_it != a.end()) {
                ll first_idx = (ll)(i + 1);
                ll second_idx = (ll)(j + 1);
                ll third_idx = find_it->second;
                
                ll min_index = min({first_idx, second_idx, third_idx});
                ll max_index = max({first_idx, second_idx, third_idx});
                ll mid_index = (first_idx + second_idx + third_idx) - max_index - min_index;
                
                cout << min_index << " " << mid_index << " " << max_index << "\n";
                return 0;
            }
        }
        a[b[i]] = i + 1;
    }
    
    cout << "IMPOSSIBLE\n";
    return 0;
}