#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Road{
    ll a;
    ll b;
    ll c;
    Road() = default;
    Road(ll p, ll q, ll r){
        a = p;
        b = q;
        c = r;
    }
};

ll shortest_dist(ll n, vector<vector<ll>> &shortest, Road road){
    ll ans = 0;
    ll c1 = road.a;
    ll c2 = road.b;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            shortest[i][j] = min({
                shortest[i][j],
                shortest[i][c1] + road.c + shortest[c2][j],
                shortest[i][c2] + road.c + shortest[c1][j]
            });
        }
    }
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j < i; j++){
            ans += shortest[i][j];
        }
    }
    return ans;
}

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

    ll n;
    cin >> n;

    vector<vector<ll>> shortest(n + 1, vector<ll>(n + 1, 0));

    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= n; j++){
            cin >> shortest[i][j];
        }
    }

    ll k;
    cin >> k;

    vector<ll> shortsum(k);

    for(ll i = 0; i < k; i++){
        ll a, b, c;
        cin >>a >>b >>c;
        Road road(a, b, c);
        shortsum[i] = shortest_dist(n, shortest, road);
    }

    for(ll i = 0; i < k; i++){
        cout << shortsum[i] <<" ";
    }
    cout <<endl;
    return 0;
}
