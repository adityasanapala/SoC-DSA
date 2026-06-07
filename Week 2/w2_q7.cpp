#include <iostream>

using namespace std;

int main() {   
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int ans = 0;
        int cur = 0;
        
        for (int i = 0; i < n - 1; i++) {
            if (a[i] < 2 * a[i + 1]) {
                cur++;
            } else {
                cur = 0;
            }
            
            if (cur >= k) {
                ans++;
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}