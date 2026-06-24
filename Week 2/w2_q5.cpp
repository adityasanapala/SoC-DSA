#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
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

    int n;
    cin >> n;

    vector<ll> sticks(n);

    for(int i =  0; i < n; i++){
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());

    ll cost = 0;
    ll target = sticks[n / 2];

    for(ll i = 0; i < n; i++){
        cost += abs(sticks[i] - target);
    }

    cout << cost <<endl;

    return 0;
}