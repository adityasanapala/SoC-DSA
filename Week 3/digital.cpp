#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int digrt(int n){
    return n == 0 ? 0 : 1 + (n - 1) % 9;
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

    int n;
    cin >>n;

    ll accepted = 0;
    ll correct = 0;
    ll ans;

    //go over the triplets and check for billy(a, b, c) and then if a * b != c, ans++
    //calculating accepted triplets

    ll cnt[10] = {};
    for(int x = 1; x <= n; x++)
        cnt[digrt(x)]++;

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            int k = digrt(i * j);
            accepted += cnt[i] * cnt[j] * cnt[k];
        }
    }
    //finding the correct triplets

    for(int a = 1; a <= n; a++){
        correct += n / a;
    }

    ans = accepted - correct;
    cout <<ans <<endl;

    //cout << digrt(9623) <<endl;

    return 0;
}