#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        
        bool has_three = false;
        int count_two = 0;
        
        for (int i = 0; i < k; ++i) {
            int c;
            cin >> c;
            
            // Check the logic conditions
            if (c >= 3) {
                has_three = true;
            }
            if (c >= 2) {
                count_two++;
            }
        }
        if (has_three || count_two >= 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    
    solve();
    
    return 0;
}