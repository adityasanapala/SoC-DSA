#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    if (s[0] != '1') {
        cout << "NO\n";
        return;
    }

    if (s[n - 1] == '9') {
        cout << "NO\n";
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        if (s[i] == '0') {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}