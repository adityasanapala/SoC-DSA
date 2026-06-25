#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int>>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define input(v,n) for(int i=0;i<n;i++) cin>>v[i]
#define pb(a) push_back(a)
#define all(a) (a).begin(),(a).end()

void solve() {
    int n,t;
    cin >> n >> t;
    vi k(n);
    input(k, n);
    int mn = *min_element(all(k));
    int lo = 0, hi = mn * t;
    int ans = 0;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        int sum = 0;
        loop(i,0,n){
            sum += (mid / k[i]);
            if(sum>=t)
                break;
        }
        if(sum>=t){
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}