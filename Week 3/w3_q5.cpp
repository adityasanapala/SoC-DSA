#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<ll>;
ll D = 1e9 + 7;

int main() {
    ll t, n;
    cin >> t;
    vint M(2), S(2);
    M[1] = 1;
    S[1] = 1;
    while (t--) {
        cin >> n;
        int size = M.size();
        if (n >= size) {
            for (int i = size; i <= n; i++) {
                S.push_back((M[i - 1] + 4 * S[i - 1]) % D);
                M.push_back((2 * M[i - 1] + S[i - 1]) % D);
            }
        }
        cout << (S[n] + M[n]) % D << endl;
    }
}
