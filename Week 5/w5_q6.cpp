#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        vector<ll> a(n+1);

        for(int i=1;i<=n;i++){
            cin>>a[i];
        }

        ll answer=-(1LL<<60);

        int start=max(1,n-200);

        for(int i=start;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ll value=1LL*i*j-1LL*k*(a[i]|a[j]);
                answer=max(answer,value);
            }
        }

        cout<<answer<<endl;
    }

    return 0;
}