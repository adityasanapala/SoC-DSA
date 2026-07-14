#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int t;
    cin>>t;
    while(t--){
        int ans = 2e9;
        int a, b;
        cin>>a>>b;
           for(int m = 1; m <= 100000; m++){
            int moves = (m-1) + (a+m-1)/m + (b+m-1)/m;
            ans = min(ans, moves);
           }
            v.push_back(ans);
    }
    for(auto x : v){
        cout<<x<<endl;
    }
    return 0;
}