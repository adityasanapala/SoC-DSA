#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    ll n,x=0,a;
    cin>>n;
    vector<ll>p;
    for(int i=0;i<n;i++){
        ll y;
        cin>>y;
        p.push_back(y);
    }
    sort(p.begin(),p.end());
    if(n%2==0){
        a=(p[n/2]+p[n/2-1])/2;
    }
    else{
        a=p[n/2];
    }
    for(int i=0;i<n;i++){
        x+=abs(p[i]-a);
    }
    cout<<x<<'\n';
}
//done 