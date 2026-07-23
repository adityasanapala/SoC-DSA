#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        bool cond = (2 * b - a) % 3 == 0 && (2 * a - b) % 3 == 0;
        if (!cond) { cout << "NO" << endl; }
        else {
            int n = (2 * b - a) / 3;
            int m = (2 * a - b) / 3;
            if (n >= 0 && m >= 0) { cout << "YES" << endl; }
            else { cout << "NO" << endl; }
        }
    }
}
