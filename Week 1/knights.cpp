#include <iostream>
using namespace std;

long long factorial(long long n) {
    if (n == 0) return 1;
    return (n * factorial(n - 1));
}

long long comb(long long n, long long k) { return (n * (n - 1)) / 2; }

int main() {
    int n;
    cin >> n;
    cout << 0 << endl;
    if (n == 1) { return 0; }
    cout << 6 << endl;
    if (n == 2) { return 0; }
    for (long long i = 3; i <= n; i++) { cout << comb(i * i, 2) - (4 * (i - 2) * (i - 1)) << endl; }
    return 0;
}
