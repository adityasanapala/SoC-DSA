#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //for faster IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //string s;
    //getline(cin, s);
    // while (cin >> x){
    //     //code
    // }

    ll n,t;
    cin >>n >>t;

    vector<ll> k(n);

    for(ll i = 0; i < n; i++){
        cin >> k[i];
    }

    ll left = 0;
    ll right = *min_element(k.begin(), k.end()) * t;
    ll ans = right;

    while(left <= right){
        ll mid = left + (right - left) / 2;
        ll products = 0;

        for (ll i = 0; i < n; i++) {
            products += mid / k[i];

            if (products >= t) {
                break;
            }
        }
        if (products >= t) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }

    }

    cout <<ans <<endl;

    return 0;
}