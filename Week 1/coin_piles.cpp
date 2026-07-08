#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {

        long long a, b;
        cin >> a >> b;

        // total no. of coins must be divisible by 3
        if((a + b) % 3 != 0) {
            cout << "NO" << endl;
        }

        // one pile cannot be more than double the other
        else if(max(a, b) > 2 * min(a, b)) {
            cout << "NO" << endl;
        }

        else {
            cout << "YES" << endl;
        }
    }

    return 0;
}