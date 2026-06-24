#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool checksort(ll i, ll k, ll arr[]){
    ll prev = arr[i];
    for(ll j = i + 1; j <= i + k; j++){
        if (2 * arr[j] <= prev)
            return false;

        prev = arr[j];
    }
    return true;
}

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

    // Your code here


    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++){
        ll n, k;
        cin >> n >>k;
        ll arr[n];
        for(ll j = 0; j < n; j++){
            cin >> arr[j];
        }
        bool good[n - 1];
        for (int i = 0; i < n - 1; i++){
            good[i] = (2 * arr[i + 1] > arr[i]);
        }
        
        int bad = 0;

        for (int i = 0; i < k; i++)
            if (!good[i]) bad++;

        ll ans = (bad == 0);

        for (int i = k; i < n - 1; i++) {
            if (!good[i]) bad++;
            if (!good[i - k]) bad--;

            if (bad == 0) ans++;
        }

        cout <<ans <<endl;
    }

}