#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        bool ok = true;
        if (s[0] != '1') ok = false;
        if (s[n - 1] == '9') ok = false;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '0') ok = false;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}