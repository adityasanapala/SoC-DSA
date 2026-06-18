#include <bits/stdc++.h>
using namespace std;

int BS;
vector<int> bit;
void upd(int i, int v) { for (; i <= BS; i += i & -i) bit[i] += v; }
int qr(int i) { int s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }

int main() {
    int n;
    scanf("%d", &n);
    vector<int> x(n), y(n), ys;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
        ys.push_back(y[i]);
    }
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    BS = ys.size();
    auto cy = [&](int v) { return (int)(lower_bound(ys.begin(), ys.end(), v) - ys.begin()) + 1; };

    vector<int> idx(n);
    for (int i = 0; i < n; i++) idx[i] = i;
    vector<int> contains(n), inside(n);

    sort(idx.begin(), idx.end(), [&](int a, int b) {
        if (x[a] != x[b]) return x[a] < x[b];
        return y[a] > y[b];
    });
    bit.assign(BS + 1, 0);
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && x[idx[j]] == x[idx[i]] && y[idx[j]] == y[idx[i]]) j++;
        int g = j - i, yc = cy(y[idx[i]]);
        int base = qr(BS) - qr(yc - 1);
        for (int t = i; t < j; t++) inside[idx[t]] = base + (g - 1);
        for (int t = i; t < j; t++) upd(cy(y[idx[t]]), 1);
        i = j;
    }

    sort(idx.begin(), idx.end(), [&](int a, int b) {
        if (x[a] != x[b]) return x[a] > x[b];
        return y[a] < y[b];
    });
    bit.assign(BS + 1, 0);
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && x[idx[j]] == x[idx[i]] && y[idx[j]] == y[idx[i]]) j++;
        int g = j - i, yc = cy(y[idx[i]]);
        int base = qr(yc);
        for (int t = i; t < j; t++) contains[idx[t]] = base + (g - 1);
        for (int t = i; t < j; t++) upd(cy(y[idx[t]]), 1);
        i = j;
    }

    for (int i = 0; i < n; i++) printf("%d ", contains[i]);
    printf("\n");
    for (int i = 0; i < n; i++) printf("%d ", inside[i]);
    printf("\n");
    return 0;
}
