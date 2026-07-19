#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max1 = 0;

    for (int M = 1; M <= 30; M++) {
        int cur = 0;
        int max2 = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] > M) {
                cur = 0;
            } else {
                cur += a[i];
                if (cur < 0) {
                    cur = 0;
                }
                if (cur > max2) {
                    max2 = cur;
                }
            }
        }
        
        int score = max2 - M;
        if (score > max1) {
            max1 = score;
        }
    }

    cout << max1 << "\n";

    return 0;
}