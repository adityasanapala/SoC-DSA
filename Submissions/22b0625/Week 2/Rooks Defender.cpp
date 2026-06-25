#include <iostream>
#include <vector>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    int sum(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    int query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> rowCnt(n + 1, 0);
    vector<int> colCnt(n + 1, 0);

    Fenwick rowTree(n), colTree(n);

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, y;
            cin >> x >> y;

            rowCnt[x]++;
            if (rowCnt[x] == 1)
                rowTree.add(x, 1);

            colCnt[y]++;
            if (colCnt[y] == 1)
                colTree.add(y, 1);
        }
        else if (t == 2) {
            int x, y;
            cin >> x >> y;

            rowCnt[x]--;
            if (rowCnt[x] == 0)
                rowTree.add(x, -1);

            colCnt[y]--;
            if (colCnt[y] == 0)
                colTree.add(y, -1);
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            int rows = rowTree.query(x1, x2);
            int cols = colTree.query(y1, y2);

            if (rows == x2 - x1 + 1 || cols == y2 - y1 + 1)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}