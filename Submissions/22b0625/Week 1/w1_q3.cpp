#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k % 2 == 0) {
            cout << (n % 2 == 0 ? "YES" : "NO") << '\n';
        } else {
            if (n % 2 == 0 || n >= k)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}