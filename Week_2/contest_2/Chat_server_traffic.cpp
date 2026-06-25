#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string> v;
    string s;
    long long traffic = 0;
    while (getline(cin, s)) {
        if(s[0] == '+') {
            v.push_back(s.substr(1));
        } 
        else if(s[0] == '-') {
            auto it = find(v.begin(), v.end(), s.substr(1));
            if (it != v.end()) {
                v.erase(it);
            }
        }
        else {
            auto it = find(s.begin(), s.end(), ':');
            if (it != s.end()) {
                size_t pos = it - s.begin()+1;
                string ip = s.substr(pos);
                traffic += v.size() * ip.length();
            }
        }
    }
    cout << traffic << endl;
    return 0;
}