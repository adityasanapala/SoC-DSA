#include <iostream>
#include <algorithm>
#include <string>

using namespace std; 

void solve() {
    int k;
    cin >> k;
    
    long long c[105];
    long long tot = 0;
    for (int i = 0; i < k; i++) {
        cin >> c[i];
        tot += c[i];
    }

    long long fib[60];
    long long pref[60];
    fib[0] = 1;
    fib[1] = 1;
    pref[0] = 1;
    pref[1] = 2;
    
    int m = -1;
    if (tot == 1) m = 0;
    if (tot == 2) m = 1;
    
    for (int i = 2; i < 60; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        pref[i] = pref[i - 1] + fib[i];
        if (pref[i] == tot) {
            m = i;
        }
    }

    if (m == -1) {
        cout << "NO\n";
        return;
    }

    int qwer = -1; 
    
    for (int j = m; j >= 0; j--) {
        int best = -1;
        
        for (int i = 0; i < k; i++) {
            if (i == qwer) continue; 
            if (best == -1 || c[i] > c[best]) {
                best = i;
            }
        }
        
        if (best == -1 || c[best] < fib[j]) {
            cout << "NO\n";
            return;
        }
        
        c[best] -= fib[j];
        qwer = best;
    }
    
    cout << "YES\n";
}

int main() {   
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}