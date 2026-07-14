#include<bits/stdc++.h>
using namespace std;

using int64 = long long;

const int MOD = 998244353;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int64> a(n+1);
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        vector<int64> mx(n+1), mn(n+1);
        vector<int> waysmx(n+1), waysmn(n+1);
        mx[0] = mn[0] = 0;
        waysmx[0] = waysmn[0] = 1;
        for(int i = 1; i <= n; i++){
            int64 candmx1 = mx[i-1] + a[i];
            int64 candmx2 = llabs(mx[i-1] + a[i]);
            int64 candmn1 = mn[i-1] + a[i];
            int64 candmn2 = llabs(mn[i-1] + a[i]);
            int64 newmx = max({candmx1, candmx2, candmn1, candmn2});
            int64 newmn = min({candmx1, candmx2, candmn1, candmn2});
            long long cntmx = 0;
            long long cntmn = 0;
            auto add = [&](int64 val, int ways){
                if(val == newmx){
                    cntmx += ways;
                    if(cntmx >= MOD) cntmx %= MOD;
                }
                if(val == newmn){
                    cntmn += ways;
                    if(cntmn >= MOD) cntmn %= MOD;
                }
            };
            if(candmx1 == candmx2){
                add(candmx1, (2LL * waysmx[i-1]) % MOD);
            }
            else{
                add(candmx1, waysmx[i-1]);
                add(candmx2, waysmx[i-1]);
            }
            if(mx[i-1] != mn[i-1]){
                if(candmn1 == candmn2){
                    add(candmn1, (2LL * waysmn[i-1])%MOD);
                }
                else{
                    add(candmn1, waysmn[i-1]);
                    add(candmn2, waysmn[i-1]);
                }
            }
            mx[i] = newmx;
            mn[i] = newmn;
            waysmx[i] = cntmx % MOD;
            waysmn[i] = cntmn % MOD;
        }
        cout<<waysmx[n]%MOD<<endl;
    }
    return 0;
}