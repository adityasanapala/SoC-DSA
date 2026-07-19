#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    int even = 0, odd = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (even == 1 && a[i] % 2 == 0) {
            cout << i + 1 << endl;
            break;
        }
        if (odd == 1 && a[i] % 2 != 0) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}