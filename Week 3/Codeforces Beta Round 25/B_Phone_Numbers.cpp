#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    string s;
 
    cin >> n >> s;
 
    vector<string> ans;
    int i = 0;
 
    if (n % 3 == 1) {
        while (n > 4) {
            ans.push_back(s.substr(i, 3));
            i += 3;
            n -= 3;
        }
        ans.push_back(s.substr(i, 2));
        ans.push_back(s.substr(i + 2, 2));
    }
    else if (n % 3 == 2) {
        while (n > 2) {
            ans.push_back(s.substr(i, 3));
            i += 3;
            n -= 3;
        }
        ans.push_back(s.substr(i, 2));
    }
    else {
        while (n) {
            ans.push_back(s.substr(i, 3));
            i += 3;
            n -= 3;
        }
    }
 
    for (int j = 0; j < ans.size(); j++) {
        if (j) cout << "-";
        cout << ans[j];
    }
}