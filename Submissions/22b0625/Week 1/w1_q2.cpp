#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 1, cur = 1;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            cur++;
        } else {
            ans = max(ans, cur);
            cur = 1;
        }
    }

    ans = max(ans, cur);

    cout << ans << '\n';
    return 0;
}