#include <iostream>
using namespace std;

void fun(long long n, long long k) {
    if (n % 2 == 1 and k % 2 == 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        fun(n, k);
    }
}
