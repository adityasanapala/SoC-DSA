#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool check(int n, int k, const int a[], int X, int qwer) {
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (l % 2 == qwer) {
            if (a[i] <= X) {
                l++;
            }
        } else {
            l++;
        }
    }
    return l >= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    int a[n];
    int low = 1, high = 1000000000;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (check(n, k, a, mid, 0) || check(n, k, a, mid, 1)) {
            ans = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;  
        }
    }

    cout << ans << "\n";

    return 0;
}