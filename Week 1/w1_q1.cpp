#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long sum = n * (n + 1) / 2;
    long long x, sumGiven = 0;

    for (long long i = 0; i < n - 1; i++) {
        cin >> x;
        sumGiven += x;
    }

    cout << sum - sumGiven << endl;

    return 0;
}