#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int main(){
    int n,m;
    cin>>n>>m;

    if(n>m){
        cout<<"YES"<<endl;
        return 0;
    }

    vector<int> dp(m,0);

    for(int i=0;i<n;i++){
        ll x;
        cin>>x;

        vector<int> next=dp;

        next[x%m]=1;

        for(int j=0;j<m;j++){
            if(dp[j]){
                next[(j+x)%m]=1;
            }
        }

        dp=next;
    }

    if(dp[0]){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}