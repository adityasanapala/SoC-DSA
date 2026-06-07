#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p, p + n);

    int median = p[n / 2];
    long long cost = 0;

    for (int i = 0; i < n; i++) {
        cost += abs(p[i] - median);
    }

    cout << cost << "\n";

    return 0;
}