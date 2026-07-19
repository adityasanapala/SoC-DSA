#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 400005;

long long qwer[MAX];
long long qwer1[MAX];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long inverse(long long n) {
    return power(n, MOD - 2);
}

void abcd() {
    qwer[0] = 1;
    qwer1[0] = 1;
    for (int i = 1; i < MAX; i++) {
        qwer[i] = (qwer[i - 1] * i) % MOD;
    }
    qwer1[MAX - 1] = inverse(qwer[MAX - 1]);
    for (int i = MAX - 2; i >= 1; i--) {
        qwer1[i] = (qwer1[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return qwer[n] * qwer1[r] % MOD * qwer1[n - r] % MOD;
}

int main() {
    abcd();

    int n;
    cin >> n;

    int a[n + 1];
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    long long tot = 0;
    for (int x = 0; x <= n; x++) {
        if (a[x] > 0) {
            tot = (tot + nCr(x + a[x], x + 1)) % MOD;
        }
    }

    cout << tot << "\n";

    return 0;
}