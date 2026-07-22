#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    vector<ll>songs;
    ll maxlen=0,left=0;
    for(int i=0;i<n;i++){
        ll y;
        cin>>y;
        songs.push_back(y);
    }
    unordered_map<ll,ll> last;
    for(int i=0;i<n;i++){
        if (last.count(songs[i])) {
            left = max(left, last[songs[i]] + 1);
        }
        last[songs[i]]=i;
        maxlen=max(maxlen,i-left+1);
    }
    cout<<maxlen<<'\n';
}
//done