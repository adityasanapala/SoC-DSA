#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int even=0, odd = 0;
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    int odd_idx = 0;
    int even_idx = 0;
    for (int x = 0; x < n;x++){
        if(v[x]%2==0){
            even++;
            even_idx = x + 1;
        }
        else{ odd++;
            odd_idx = x + 1;
        }
    }
    if(even==1)
        cout<< even_idx<<"\n";
    else
        cout<< odd_idx<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}