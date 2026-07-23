#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll pw2[400000];
    pw2[0] = 1;
        for(int i = 1; i < 400000; i++){
            pw2[i] = 2*pw2[i-1] % MOD;
        }
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        ll ans = 0, minimum = 0, sum = 0;
        for(ll i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
            minimum = min(sum, minimum);
        }
        if(minimum == 0){
            // the value never goes below zero
            cout << (pw2[n])%MOD << '\n';
        }
        else{
            //if the value does go below zero, then there will be only one place where the second
            // operation is used.
            ll sum2 = 0, pos = 0;
            for(ll i = 0; i < n; i++){
                sum2 += a[i];
                if(sum2 == minimum){
                    ans = (ans + (pw2[pos + n - i - 1])) % MOD;
                }
                if(sum2 >= 0){
                    pos++;
                }
            }
            cout << ans <<'\n';
        }
    }
    return 0;
}