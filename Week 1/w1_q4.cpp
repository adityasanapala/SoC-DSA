#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getLuckiness(int num) {
    string s = to_string(num);

    char minDigit = s[0];
    char maxDigit = s[0];

    for (int i = 1; i < s.length(); i++) {
        if (s[i] < minDigit) {
            minDigit = s[i];
        }
        if (s[i] > maxDigit) {
            maxDigit = s[i];
        }
    }

    return maxDigit - minDigit;
}

vector<int> byLuck[10];

int main() {
    for (int i = 1; i <= 1000000; i++) {
        int luck = getLuckiness(i);
        byLuck[luck].push_back(i);
    }

    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        for (int luck = 9; luck >= 0; luck--) {
            auto it = lower_bound(byLuck[luck].begin(), byLuck[luck].end(), l);
            if (it != byLuck[luck].end() && *it <= r) {
                cout << *it << endl;
                break;
            }
        }
    }

    return 0;
}