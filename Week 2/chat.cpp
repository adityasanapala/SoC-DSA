#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //for faster IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    //getline(cin, s);
    ll ans = 0;
    ll cnt = 0;
    while (getline(cin, s)){
        if(s[0] == '+'){
            cnt++;
        }
        else if(s[0] == '-'){
            cnt--;
        }
        else{
            ll idx= s.find(':');
            ll l = s.length() - idx - 1;
            ans += l * cnt;
        }
    }

    cout << ans << endl;
    return 0;
}