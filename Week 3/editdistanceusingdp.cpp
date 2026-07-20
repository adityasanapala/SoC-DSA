#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<ll>;
string A, B;
ll n, m;

int main() {
    cin >> A >> B;
    n = A.size();
    m = B.size();
    vector<vector<ll>> V(n + 1, vector<ll>(m + 1, -1));
    for (ll i = 0; i <= n; i++) { V[i][0] = i; }
    for (ll i = 0; i <= m; i++) { V[0][i] = i; }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1]) { V[i][j] = V[i - 1][j - 1]; }
            else { V[i][j] = 1 + min(V[i - 1][j - 1], min(V[i][j - 1], V[i - 1][j])); }
        }
    }
    cout << V[n][m] << endl;
}
