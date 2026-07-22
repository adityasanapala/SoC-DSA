#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    ll n,t,mn=1000000001;
    cin>>n>>t;
    vector<ll>k;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        k.push_back(a);
        mn=min(mn,a);
    }
    ll l=0,r=mn*t,res=0;
    while(l<=r){
        ll mid=(l+r)/2;
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=(mid/k[i]);
            if(sum>=t)break;
        }
        if(sum>=t){
            res=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<res<<endl;
}
//done