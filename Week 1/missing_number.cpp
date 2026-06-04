#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long sum = n * (n + 1) / 2;
    long long x, givenSum = 0;

    for (long long i = 0; i < n - 1; i++) {
        cin >> x;
        givenSum += x;
    }

    cout << sum - givenSum << endl;

    return 0;
}