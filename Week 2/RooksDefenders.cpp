#include <bits/stdc++.h>
using namespace std;

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
        while (idx) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    BIT rowBIT(n), colBIT(n);
    vector<int> rowCnt(n + 1), colCnt(n + 1);

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, y;
            cin >> x >> y;

            if (++rowCnt[x] == 1)
                rowBIT.update(x, 1);

            if (++colCnt[y] == 1)
                colBIT.update(y, 1);
        }

        else if (t == 2) {
            int x, y;
            cin >> x >> y;

            if (--rowCnt[x] == 0)
                rowBIT.update(x, -1);

            if (--colCnt[y] == 0)
                colBIT.update(y, -1);
        }

        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            if (rowBIT.rangeQuery(x1, x2) == x2 - x1 + 1 ||
                colBIT.rangeQuery(y1, y2) == y2 - y1 + 1)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}