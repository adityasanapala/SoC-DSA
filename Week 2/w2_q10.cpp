#include <iostream>

using namespace std;

int bit_row[100005];
int bit_col[100005];
int row_cnt[100005];
int col_cnt[100005];
int n, q;

void update_row(int idx, int val) {
    while (idx <= n) {
        bit_row[idx] += val;
        idx += idx & -idx;
    }
}

int query_row(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit_row[idx];
        idx -= idx & -idx;
    }
    return sum;
}

void update_col(int idx, int val) {
    while (idx <= n) {
        bit_col[idx] += val;
        idx += idx & -idx;
    }
}

int query_col(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit_col[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int main() {
    cin >> n >> q;

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            if (row_cnt[x] == 0) {
                update_row(x, 1);
            }
            row_cnt[x]++;
            if (col_cnt[y] == 0) {
                update_col(y, 1);
            }
            col_cnt[y]++;
        } else if (t == 2) {
            int x, y;
            cin >> x >> y;
            row_cnt[x]--;
            if (row_cnt[x] == 0) {
                update_row(x, -1);
            }
            col_cnt[y]--;
            if (col_cnt[y] == 0) {
                update_col(y, -1);
            }
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            
            int rows = query_row(x2) - query_row(x1 - 1);
            int cols = query_col(y2) - query_col(y1 - 1);
            
            if (rows == (x2 - x1 + 1) || cols == (y2 - y1 + 1)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}