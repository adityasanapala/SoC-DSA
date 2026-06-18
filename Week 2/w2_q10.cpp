#include <bits/stdc++.h>
using namespace std;

int n;
int br[100005], bc[100005], rc[100005], cc[100005];
void upd(int *b, int i, int v) { for (; i <= n; i += i & -i) b[i] += v; }
int qr(int *b, int i) { int s = 0; for (; i > 0; i -= i & -i) s += b[i]; return s; }

int main() {
    int q;
    scanf("%d %d", &n, &q);
    while (q--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (rc[x]++ == 0) upd(br, x, 1);
            if (cc[y]++ == 0) upd(bc, y, 1);
        } else if (t == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (--rc[x] == 0) upd(br, x, -1);
            if (--cc[y] == 0) upd(bc, y, -1);
        } else {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            int rows = qr(br, x2) - qr(br, x1 - 1);
            int cols = qr(bc, y2) - qr(bc, y1 - 1);
            printf(rows == x2 - x1 + 1 || cols == y2 - y1 + 1 ? "Yes\n" : "No\n");
        }
    }
    return 0;
}
