#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string line;
    int current_users = 0;
    int total_traffic = 0;
    while (getline(cin, line)){
        if (line.empty()) continue;
        if (line[0] == '+') current_users++;
        else if (line[0] == '-') current_users--;
        else{
            size_t colon_pos = line.find(':');
            string message = line.substr(colon_pos + 1);
            total_traffic += message.length() * current_users;
        }
    }
    cout << total_traffic << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}