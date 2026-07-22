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
    int n;
    cin>>n;
    vi a(n);
    input(a,n);
    vi b = a;
    sort(b.begin(), b.end());
    vi prev(n);
    vi curr(n);
    prev[0] = abs(a[0]-b[0]);
    loop(i,1,n) prev[i] = min(abs(a[0]-b[i]), prev[i-1]);
    loop(i,1,n){
        loop(j,0,n) {
            if (j == 0) {
                curr[j] = abs(a[i]-b[0])+prev[0];
            }
            else curr[j] = min(curr[j-1], prev[j]+abs(a[i]-b[j]));
        }
        prev = curr;
    }
    cout << curr[n-1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
}