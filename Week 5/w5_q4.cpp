#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

ll jumps(ll dist, ll m){
    ll ans = dist / m;
    ll rem = dist % m;

    for(ll len = m - 1; len >= 1 && rem > 0; len--){
        if(rem >= len){
            rem -= len;
            ans++;
        }
    }

    return ans;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        ll a, b;
        cin >> a >> b;

        ll answer = a + b;

        for(ll m = 1; m * m <= 2000000000LL; m++){
            ll moves = (m - 1) + jumps(a, m) + jumps(b, m);
            answer = min(answer, moves);
        }

        cout << answer << endl;
    }

    return 0;
}