#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    vector<string> lines;
    string s;
    size_t max_width = 0;
    while (getline(cin, s)){
        lines.push_back(s);
        max_width = max(max_width, s.length());
    }
    cout << string(max_width + 2, '*') << "\n";

    bool b = true; 
    for (const string &l : lines){
        int tot = max_width - l.length();
        int left = tot / 2;
        int right = tot / 2;

        if (tot % 2 != 0){
            if (b) right++;
            else left++;
            b = !b; 
        }
        cout << "*" << string(left, ' ') << l << string(right, ' ') << "*\n";
    }
    cout << string(max_width + 2, '*') << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}