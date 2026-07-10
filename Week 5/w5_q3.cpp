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

    // 1. First digit should not be 1
    // 2. Last digit can't be 9
    // 3. Middle digits can't be 0
    int t;
    cin >> t;
    while(t--){
        bool possible = true;
        ll n;
        cin >> n;
        string s = to_string(n);
        int len = s.length();
        if(s[0] != '1' || (n % 10 == 9)){
            possible = false;
        }
        for(int i = 1; i <= len - 2; i++){
            if(s[i] == '0') possible = false;
        }
        (possible) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
