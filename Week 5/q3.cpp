#include<iostream>
#include<string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        bool ok = true;

        if (s[0] != '1') ok = false;
        if (s.back() == '9') ok = false;

        for (int i = 1; i < (int)s.size() - 1; i++) {
            if (s[i] == '0') {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}