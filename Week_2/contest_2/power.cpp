#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fo(i,n) for(int i=0;i<n;i++)

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll p1,p2,p3,t1,t2,n,x,y,totalpower=0,delta;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    
    vector<pair<ll,ll>> v;
    fo(i,n){
        cin >> x >> y;
        v.push_back({x,y});
    }
    
    fo(i,n){
        totalpower += p1*(v[i].second - v[i].first);
        if(i < n-1){
            delta = v[i+1].first - v[i].second;
            if(delta > t1){
                totalpower += p1 * t1;
                if(delta - t1 > t2){
                    totalpower += p2 * t2;
                    totalpower += p3 * (delta - t1 - t2);
                }
                else{
                    totalpower += p2 * (delta - t1);
                }
            }
            else{
                totalpower += p1 * delta;
            }
        }
    }
    
    cout << totalpower << "\n";
    return 0;
}