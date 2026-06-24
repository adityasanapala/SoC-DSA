#include <bits/stdc++.h>
#include <sys/types.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        vector<ll> b = a;
        sort(b.begin(), b.end());
        vector<ll> prev(n);
        vector<ll> curr(n);
        prev[0] = abs(a[0]-b[0]);
        for (ll i = 1 ; i < n ; i ++) prev[i] = min(abs(a[0]-b[i]), prev[i-1]);
        for (ll i = 1 ; i < n ; i ++) {
            for (ll j = 0 ; j < n ; j ++) {
                if (j == 0) {
                    curr[j] = abs(a[i]-b[0])+prev[0];
                }
                else curr[j] = min(curr[j-1], prev[j]+abs(a[i]-b[j]));
            }
            prev = curr;
        }
        cout << curr[n-1];

    return 0;
}
