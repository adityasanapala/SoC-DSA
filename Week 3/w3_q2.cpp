#include <iostream>

using namespace std;

int main() {
    int n;
    long long t;
    cin >> n >> t;

    int k[n]; 
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    long long low = 1;
    long long high = 1e18; 
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        long long products = 0;
        for (int i = 0; i < n; i++) {
            products += (mid / k[i]);
            if (products >= t) {
                break;
            }
        }

        if (products >= t) {
            ans = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;  
        }
    }

    cout << ans << "\n";

    return 0;
}