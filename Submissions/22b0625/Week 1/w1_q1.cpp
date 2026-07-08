#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;

    for (int i = 1; i <= n; i++) ans ^= i;

    for (int i = 0, x; i < n - 1; i++) {
        cin >> x;
        ans ^= x;
    }

    cout << ans;
    return 0;
}