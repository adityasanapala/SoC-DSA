#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
int main(){
    ll n,found=0;
    cin>>n;
    vector<ll>coins;
    for(int i=0;i<n;i++){
        ll y;
        cin>>y;
        coins.push_back(y);
    }
    ll MAX=min(2*coins[0],30000000LL);
    vector<ll>optimal(MAX+1,1e18);
    optimal[0]=0;
    for(ll i=1;i<=MAX;i++){
        ll best=1e18;
        ll g=0;
        ll k=i;
        for(auto c :coins){
            if(i>=c) best=min(best,optimal[i-c]+1);
            g+=k/c;
            k=k%c;
        }
        optimal[i]=best;
        if(g>optimal[i]){
            cout<<i<<'\n';
            found=1;
            break;
        }
    }
    if(found==0)cout<<-1<<'\n';
}