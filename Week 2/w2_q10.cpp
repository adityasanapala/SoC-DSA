#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    ll n,q;
    cin>>n>>q;
    vector<ll>row(n+1,0);
    vector<ll>col(n+1,0);
    for(int i=0;i<q;i++){
        ll t;
        cin>>t;
        if(t==1){
            ll x,y;
            cin>>x>>y;
            row[x]++;
            col[y]++;
        }
        else if(t==2){
            ll x,y;
            cin>>x>>y;
            row[x]--;
            col[y]--;
        }
        else if(t==3){
            ll x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            ll ra=1,rc=1;
            for(int i=x1;i<=x2;i++){
                if(row[i]==0){
                    ra =0;
                    break;
                }
            }
            for(int i=y1;i<=y2;i++){
                if(col[i]==0){
                    rc=0;
                    break;
                }
            }
            if(ra==0&&rc==0)cout<<"No\n";
            else cout<<"Yes\n";
        }
    }
}
//done