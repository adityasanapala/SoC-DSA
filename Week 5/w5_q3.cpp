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
    int x;
    cin >> x;
    int n = x;
    n = n / 10;
    int dig = 0;
    while(n>0){
        dig = n % 10;
        if(dig==0){
            cout << "NO" << endl;
            return;
        }
        n = n / 10;
    }
    if(dig==1&&(x%10)>=0&&(x%10)<=8){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}