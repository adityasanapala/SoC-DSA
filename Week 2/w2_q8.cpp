//Longest k-good Segment

#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;
using ll = long long;

int main(){
    ll n,k,x=0,l=0,r=0,l_max=0,r_max=0;
    scanf("%lld %lld", &n, &k);
    vector<ll> v(n);
    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
        scanf("%lld",&v[i]);
    }
    mp[v[0]]=1;
    for(int i=1;i<n;i++){
        mp[v[i]]++;
        r++;
        while((ll)mp.size()>k){
            mp[v[l]]--;
            if(mp[v[l]]==0){
                mp.erase(v[l]);
            }
            l++;
        }
        if(r_max-l_max <  r-l && (ll)mp.size()<k+1){
            l_max=l;
            r_max=r;
        }
    }
    printf("%lld %lld\n",l_max+1,r_max+1);
}