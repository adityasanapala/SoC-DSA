#include <bits/stdc++.h>
using namespace std;

struct Mask {
    uint64_t a[16];
    Mask() {
        for (int i = 0; i < 16; ++i) a[i] = 0;
    }
};

Mask get_mask(long long X, int n) {
    Mask m;
    if (X == 0) return m;
    int lenX = 64 - __builtin_clzll(X);
    for (int i = 0; i < n; ++i) {
        int bit = (X >> (lenX - 1 - (i % lenX))) & 1;
        if (bit) {
            m.a[i / 64] |= (1ULL << (63 - (i % 64)));
        }
    }
    return m;
}

bool less_than(const Mask& lhs, const Mask& rhs) {
    for (int i = 0; i < 16; ++i) {
        if (lhs.a[i] != rhs.a[i]) {
            return lhs.a[i] < rhs.a[i];
        }
    }
    return false;
}

void solve() {
    long long l, r;
    int n;
    cin >> l >> r >> n;

    vector<long long> E;
    vector<long long> sz;
    long long curr = l;
    while (curr <= r) {
        long long step = curr & -curr;
        if (step == 0) step = 1ll << 60;
        while (curr + step - 1 > r) step >>= 1;
        E.push_back(curr);
        sz.push_back(step);
        curr += step;
    }

    int m_size = E.size();
    vector<Mask> masks(m_size);
    for (int i = 0; i < m_size; ++i) {
        masks[i] = get_mask(E[i], n);
    }

    Mask best_mask;
    for (int i = 0; i < n; ++i) {
        best_mask.a[i / 64] |= (1ULL << (63 - (i % 64)));
    }

    for (int i = 0; i < m_size; ++i) {
        if (sz[i] >= 2) {
            if (less_than(masks[i], best_mask)) {
                best_mask = masks[i];
            }
        }
        for (int j = i + 1; j < m_size; ++j) {
            Mask comb;
            for (int k = 0; k < 16; ++k) {
                comb.a[k] = masks[i].a[k] & masks[j].a[k];
            }
            if (less_than(comb, best_mask)) {
                best_mask = comb;
            }
        }
    }

    string ans = "";
    for (int i = 0; i < n; ++i) {
        if ((best_mask.a[i / 64] >> (63 - (i % 64))) & 1) {
            ans += '1';
        } else {
            ans += '0';
        }
    }
    cout << ans << "\n";
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}