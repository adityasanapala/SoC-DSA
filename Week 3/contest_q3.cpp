#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    ll c[9];
    ll a=n/9;
    ll b=n%9;
    c[0]=a;
    for (int i=1;i<9;i++){
        if(i<=b)c[i]=a+1;
        else c[i]=a;
    }
    ll accepted=0;
    for (int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            accepted+=c[i]*c[j]*c[(i*j)%9];
        }
    }
    ll correct=0;
    for(int i=1;i<=n;i++){
        correct+=n/i;
    }
    cout<<accepted-correct<<'\n';
}