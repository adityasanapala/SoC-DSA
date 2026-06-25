#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;

int main(){
    ll n,t;
    cin >>n >>t;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++){
        cin >> v[i];
    }
    ll left = 0;
    ll right = *min_element(v.begin(), v.end()) * t;
    ll ans = right;

    while(left <= right){
        ll mid = left + (right - left) / 2;
        ll products = 0;

        for (ll i = 0; i < n; i++) {
            products += mid / v[i];

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