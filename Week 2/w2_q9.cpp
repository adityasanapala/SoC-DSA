#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    vector<ll>l;
    vector<ll>r;
    vector<ll>contained(n,0);
    vector<ll>contains(n,0);
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        l.push_back(x);
        r.push_back(y);
    }
    for(int i=0;i<n;i++){
        ll a=l[i],b=r[i];
        for(int j=0;j<n;j++){
            if(l[j]<=a&&r[j]>=b)contained[i]++;
            if(l[j]>=a&&r[j]<=b)contains[i]++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<contains[i]-1<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<contained[i]-1<<" ";
    }
}
//done