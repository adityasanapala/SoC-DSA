#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void addRookDefender(int x, int y, vector<int>& row, vector<int>& col) {
    row[x]++;
    col[y]++;
    return;
}

void removeRookDefeder(int x, int y, vector<int>& row, vector<int>& col) {
    row[x]--;
    col[y]--;
    return;
}

void rookDefender(int x1, int y1, int x2, int y2, vector<int>& row, vector<int>& col, int n) {
    int startX = min(x1, x2);
    int endX = max(x1, x2);
    int startY = min(y1, y2);
    int endY = max(y1, y2);

    vector<int> row_prefix(n + 1, 0);
    vector<int> col_prefix(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        row_prefix[i] = row_prefix[i - 1] + (row[i] > 0 ? 1 : 0);
        col_prefix[i] = col_prefix[i - 1] + (col[i] > 0 ? 1 : 0);
    }

    int total_rows_with_rooks = row_prefix[endX] - row_prefix[startX - 1];
    int total_cols_with_rooks = col_prefix[endY] - col_prefix[startY - 1];

    if (total_rows_with_rooks == (endX - startX + 1) || total_cols_with_rooks == (endY - startY + 1)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<int> row(n + 1, 0);
    vector<int> col(n + 1, 0);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            addRookDefender(x, y, row, col);
        }
        if (t == 2) {
            int x, y;
            cin >> x >> y;
            removeRookDefeder(x, y, row, col);
        }
        if (t == 3) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            rookDefender(x1, y1, x2, y2, row, col, n);
        }
    }
    return 0;
}