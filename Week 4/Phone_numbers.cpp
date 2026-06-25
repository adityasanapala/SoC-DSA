#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin>>n;
    string s;
    cin >> s;
    vector<char> ans;
    for (int i = 0; i < n;i++){
        char c = s[i];
        if (n % 2 != 0 && i >= n - 3){
            if (i == n - 3 && i > 0){
                ans.push_back('-');
            }
            ans.push_back(c);
        }
        else{
            if (i > 0 && i % 2 == 0){
                ans.push_back('-');
            }
            ans.push_back(c);
        }
    }
    for (int i = 0; i < ans.size();i++){
        cout << ans[i];
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}