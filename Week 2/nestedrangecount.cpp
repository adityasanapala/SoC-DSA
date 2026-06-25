#include <bits/stdc++.h>
using namespace std;

struct Range {
    int l, r, idx;
};

struct BIT {
    int n;
    vector<int> bit;

    BIT(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
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

    // coordinate compression
    sort(rights.begin(), rights.end());
    rights.erase(unique(rights.begin(), rights.end()), rights.end());

    auto compress = [&](int x) {
        return lower_bound(rights.begin(), rights.end(), x) - rights.begin() + 1;
    };

    sort(a.begin(), a.end(), [](Range A, Range B) {
        if (A.l == B.l)
            return A.r > B.r;
        return A.l < B.l;
    });

    vector<int> contains(n), contained(n);

    // -------- contains --------
    BIT bit(rights.size());

    for (int i = n - 1; i >= 0; i--) {
        int pos = compress(a[i].r);
        contains[a[i].idx] = bit.query(pos);
        bit.update(pos, 1);
    }

    // -------- contained --------
    BIT bit2(rights.size());

    int processed = 0;

    for (int i = 0; i < n; i++) {
        int pos = compress(a[i].r);

        contained[a[i].idx] =
            processed - bit2.query(pos - 1);

        bit2.update(pos, 1);
        processed++;
    }

    for (int x : contains)
        cout << x << " ";
    cout << "\n";

    for (int x : contained)
        cout << x << " ";
    cout << "\n";
}
