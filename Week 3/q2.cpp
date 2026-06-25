#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    ll n,t;
    cin>>n>>t;
    ll mn=1e18,a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        mn = min(mn,a[i]);
    }
    long long low = 0;
    long long high = mn * t;

    while(low<high){
        long long mid = low +(high-low)/2;
        long long products =0;
        for(int i=0;i<n;i++){
            products=products+mid/a[i];
            if (products >= t) {
                break;
            }
        }
        if (products >= t) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout<<low<<"\n";
    return 0;
}
