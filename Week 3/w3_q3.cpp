#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e9 + 7;

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

    ll ways[n + 1]{0};

    ways[0] = 0;
    for(ll i = 1; i <= n; i++){
        if(i > 6){
            ways[i] = (ways[i - 1] + ways[i - 2] + ways[i - 3] + ways[i - 4] + ways[i - 5] + ways[i - 6]) % N;
        }
        else{
            for(ll j = 1; j < i; j++){
                ways[i] += (ways[j]) % N;
            }
            ways[i]++;
        }
    }

    cout << ways[n] <<endl;

    return 0;
}