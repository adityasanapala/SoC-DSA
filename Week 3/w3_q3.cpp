#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll mod =1e9+7;
    ll a[n+1];
    for(int i=1;i<=n;i++){a[i]=0;}
    a[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6&&j<=i;j++){
            a[i]=(a[i]+(a[i-j]))% mod;
        }
    }
    cout<<a[n]<<endl;
}
//done