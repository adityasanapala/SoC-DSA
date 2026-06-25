#include <iostream>
#include <vector>

using namespace std;

// Fenwick Tree (Binary Indexed Tree) implementation
struct FenwickTree {
    int n;
    vector<int> tree;
    
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}
    
    void add(int i, vector<int>& counts) {
        // If it's the first rook in this row/col, mark it as active (1)
        if (counts[i] == 1) {
            for (; i <= n; i += i & -i) tree[i] += 1;
        }
    }
    
    void remove(int i, vector<int>& counts) {
        // If the last rook was removed, mark it as inactive (-1)
        if (counts[i] == 0) {
            for (; i <= n; i += i & -i) tree[i] -= 1;
        }
    }
    
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
    
    int query_range(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    if (!(cin >> n >> q)) return 0;
    
    vector<int> row_counts(n + 1, 0);
    vector<int> col_counts(n + 1, 0);
    
    FenwickTree row_bit(n);
    FenwickTree col_bit(n);
    
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            row_counts[x]++;
            col_counts[y]++;
            row_bit.add(x, row_counts);
            col_bit.add(y, col_counts);
        } else if (t == 2) {
            int x, y;
            cin >> x >> y;
            row_counts[x]--;
            col_counts[y]--;
            row_bit.remove(x, row_counts);
            col_bit.remove(y, col_counts);
        } else if (t == 3) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            
            bool all_rows_covered = (row_bit.query_range(x1, x2) == (x2 - x1 + 1));
            bool all_cols_covered = (col_bit.query_range(y1, y2) == (y2 - y1 + 1));
            
            if (all_rows_covered || all_cols_covered) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
    
    return 0;
}