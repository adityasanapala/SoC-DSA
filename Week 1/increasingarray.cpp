#include <iostream>
#include <vector>
using namespace std;
using vint = vector<long long>;

int main() {
    long long n;
    long long ans = 0;
    cin >> n;
    vint v(n);
    for (long long i = 0; i < n; i++) { cin >> v[i]; }
    for (long long i = 1; i < n; i++) {
        while (v[i] < v[i - 1]) {
            v[i]++;
            ans++;
        }
    }
    cout << ans << endl;
}
