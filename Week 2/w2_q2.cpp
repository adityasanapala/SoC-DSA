#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    ll n,x,p=-1,q=-1,k,m;
    cin>>n>>x;
    vector<ll>a;
    for(int i=0;i<n;i++){
        ll y;
        cin>>y;
        a.push_back(y);
    }
    vector<ll>b=a;
    sort(b.begin(),b.end());
    ll l=0,r=n-1;
    while(l<r){
        if((b[l]+b[r])>x)r--;
        else if((b[l]+b[r])<x)l++;
        else{
            p=b[l];
            q=b[r];
            break;
        }
    }
    if(p==-1||q==-1)cout<<"IMPOSSIBLE";
    else{
        for(int i=0;i<n;i++){
            if(a[i]==p){k=i; break;}
        }
        for(int i=0;i<n;i++){
            if(a[i]==q&&k!=i){m=i; break;}
        }
        cout<<k+1<<" "<<m+1;
    }
}
//done