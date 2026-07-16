
#include <iostream>
  #include <map>
  #include <algorithm>
  #include <map>
  #include <vector>
  #include <set>
using namespace std;

const int MOD = 1e9 + 7;

int main() {

    int t;
    cin >> t;

    vector<int> q(t);
    int mx = 0;

    for (int i = 0; i < t; i++) {
        cin >> q[i];
        mx = max(mx, q[i]);
    }

    vector<long long> same(mx + 1), joined(mx + 1);

    same[1] = 1;
    joined[1] = 1;

    for (int i = 2; i <= mx; i++) {
        same[i] = (4LL * same[i - 1] + joined[i - 1]) % MOD;
        joined[i] = (same[i - 1] + 2LL * joined[i - 1]) % MOD;
    }

    for (int n : q) {
        cout << (same[n] + joined[n]) % MOD << '\n';
    }

    return 0;
}
