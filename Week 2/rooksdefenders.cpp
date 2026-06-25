#include <iostream>
#include <vector>

using namespace std;

struct BIT {
    int n;
    vector<int> tree;

    BIT(int n) {
        this->n = n;
        tree.assign(n + 1, 0);
    }

    void add(int i, int val) {
        for (; i <= n; i += (i & -i)) {
            tree[i] += val;
        }
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= (i & -i)) {
            sum += tree[i];
        }
        return sum;
    }

    int queryRange(int L, int R) {
        return query(R) - query(L - 1);
    }
};

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    BIT rowBIT(n);
    BIT colBIT(n);

    vector<int> rowCount(n + 1, 0);
    vector<int> colCount(n + 1, 0);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x, y;
            cin >> x >> y;
            
            rowCount[x]++;
            if (rowCount[x] == 1) rowBIT.add(x, 1);
            
            colCount[y]++;
            if (colCount[y] == 1) colBIT.add(y, 1);
            
        } else if (type == 2) {
            int x, y;
            cin >> x >> y;
            
            rowCount[x]--;
            if (rowCount[x] == 0) rowBIT.add(x, -1);
            
            colCount[y]--;
            if (colCount[y] == 0) colBIT.add(y, -1);
            
        } else if (type == 3) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            
            int active_rows = rowBIT.queryRange(x1, x2);
            int active_cols = colBIT.queryRange(y1, y2);
            
            if (active_rows == (x2 - x1 + 1) || active_cols == (y2 - y1 + 1)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}