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
    int n,q;
    cin >> n >> q;
    vi X(n+1,0);
    vi Y(n+1,0);
    set<int> empty_row, empty_col;
    loop(i,0,n+1){
        empty_row.insert(i);
        empty_col.insert(i);
    }
    while (q--){
        int t;
        cin >> t;
        if (t == 1){
            int x, y;
            cin >> x >> y;
            X[x]++;
            Y[y]++;
            empty_row.erase(x);
            empty_col.erase(y);
        }
        else if (t == 2){
            int x, y;
            cin >> x >> y;
            X[x]--;
            Y[y]--;
            if (X[x] == 0) empty_row.insert(x);
            if (Y[y] == 0) empty_col.insert(y);
        }
        else if (t == 3){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            bool r = false;
            bool c = false;
            
            auto it_row = empty_row.lower_bound(x1);
            if(it_row!=empty_row.end()&&*it_row<=x2){
                r = true;
            }
            auto it_col = empty_col.lower_bound(y1);
            if(it_col!=empty_col.end()&&*it_col<=y2){
                c= true;
            }
            if(r&&c){
                cout << "No" << endl;
            }
            else
                cout << "Yes" << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}