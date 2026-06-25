#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    int query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

struct Range {
    int l, r, idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Range> a(n);
    vector<int> rights;

    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].idx = i;
        rights.push_back(a[i].r);
    }

    sort(rights.begin(), rights.end());
    rights.erase(unique(rights.begin(), rights.end()), rights.end());

    for (int i = 0; i < n; i++) {
        a[i].r = lower_bound(rights.begin(), rights.end(), a[i].r)
                 - rights.begin() + 1;
    }

    sort(a.begin(), a.end(), [](const Range& A, const Range& B) {
        if (A.l == B.l) return A.r > B.r;
        return A.l < B.l;
    });

    vector<int> contains(n), containedBy(n);

    Fenwick bit1(rights.size());

    for (int i = n - 1; i >= 0; i--) {
        contains[a[i].idx] = bit1.query(a[i].r);
        bit1.update(a[i].r, 1);
    }

    Fenwick bit2(rights.size());

    for (int i = 0; i < n; i++) {
        containedBy[a[i].idx] =
            bit2.query(a[i].r, rights.size());
        bit2.update(a[i].r, 1);
    }

    for (int i = 0; i < n; i++) {
        cout << contains[i] << (i + 1 == n ? '\n' : ' ');
    }

    for (int i = 0; i < n; i++) {
        cout << containedBy[i] << (i + 1 == n ? '\n' : ' ');
    }

    return 0;
}