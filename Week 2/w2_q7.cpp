// 2^Sort

#include <iostream>
#include <vector>
using namespace std;
using ll= long long;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k,cnt=0,ans=0;
        cin>>n>>k;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        for(int i=0;i<k;i++){
            if(v[i]<2*v[i+1])cnt++;
        }
        if(cnt==k)ans++;
        for(int i=k;i<n-1;i++){
            if(v[i]<2*v[i+1])cnt++;
            if(v[i-k]<2*v[i-k+1]){
                cnt--;
            }
            if(cnt==k)ans++;
        }
        cout<<ans<<"\n";
    }
}