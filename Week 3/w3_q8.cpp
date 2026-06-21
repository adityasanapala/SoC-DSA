#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    vector<ll>a;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        a.push_back(x);
    }
    vector<ll>v=a;
    sort(v.begin(),v.end());
    vector<ll>ap(n),ac(n);
    ap[0]=abs(a[0]-v[0]);
    for(int j=1;j<n;j++)ap[j]=min(abs(a[0]-v[j]),ap[j-1]);
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0)ac[j]=abs(a[i]-v[0])+ap[0];
            else ac[j]=min(ac[j-1],ap[j]+abs(a[i]-v[j]));
        }
        ap=ac;
    }
    cout<<ac[n-1]<<endl;
}
//done