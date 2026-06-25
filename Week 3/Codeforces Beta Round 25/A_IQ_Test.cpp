#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<int> a(n);
    int even = 0, odd = 0;
 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2) odd++;
        else even++;
    }
 
    for(int i = 0; i < n; i++) {
        if(even == 1 && a[i] % 2 == 0) {
            cout << i + 1;
            return 0;
        }
        if(odd == 1 && a[i] % 2) {
            cout << i + 1;
            return 0;
        }
    }
}