#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {

        cin >> n;

        int p[n + 1];

        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            p[x] = j + 1;
        }

        int left = (n + 1) / 2;
        int right = n / 2 + 1;

        if (left != right && p[left] > p[right]) {
            cout << left << '\n';
            continue;
        }

        while (left > 1 && right < n) {

            bool left_ok = (p[left - 1] < p[left]);
            bool right_ok = (p[right] < p[right + 1]);

            if (left_ok && right_ok) {
                left--;
                right++;
            } else {
                break;
            }
        }

        cout << left - 1 << '\n';
    }
}