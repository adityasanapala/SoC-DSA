#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    ll N,W;
    cin>>N>>W;
    vector<ll>w;
    vector<ll>v;
    for(int i=0;i<N;i++){
        ll a,b;
        cin>>a>>b;
        w.push_back(a);
        v.push_back(b);
    }
    const ll maxv=100000;
    const ll inf=1e18;
    vector<ll>dp(maxv+1,inf);
    dp[0]=0;
    for(int i=0;i<N;i++){
        for(int val=maxv;val>=v[i];val--){
            dp[val]=min(dp[val],dp[val-v[i]]+w[i]);
        }
    }
    for(int i=maxv;i>0;i--){
        if(dp[i]<=W){
            cout<<i<<endl;
            break;
        }
    } 
}
//done