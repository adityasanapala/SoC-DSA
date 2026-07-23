#include <bits/stdc++.h>
using namespace std;

void solve(){
    string x;
    cin >> x;
    int n=x.size();
    if(x[0]!='1'){
        cout<<"NO\n";
        return;
    }
    if(x[n-1]=='9'){
        cout<<"NO\n";
        return;
    }
    for(int i=1;i<n-1;i++){
        if(x[i]=='0'){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}