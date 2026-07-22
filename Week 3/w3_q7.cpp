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
    int x,n;
    cin>>x>>n;
    vi d(n);
    input(d,n);
    sort(all(d));
    vi merged;
    merged.reserve(n);
    int cost=0;
    int i=0,j=0;
    auto min = [&]() {
        if (i < n && (j >= merged.size() || d[i] <= merged[j])) {
            return d[i++];
        }
        else return merged[j++];
    };
    loop(k,0,n-1){
        int first=min();
        int second=min();
        int new_stick=first+second;
        cost+=new_stick;
        merged.pb(new_stick);
    }
    cout<<cost<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
}