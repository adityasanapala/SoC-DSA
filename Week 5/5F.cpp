#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 6000000;
int tr_l[MAX_NODES];
int tr_r[MAX_NODES];
int tr_size[MAX_NODES];
int tr_val[MAX_NODES];

int root;
int node_cnt = 0;

uint32_t xorshift32() {
    static uint32_t state = 1337;
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}

inline int clone(int u) {
    if (!u) return 0;
    int v = ++node_cnt;
    tr_l[v] = tr_l[u];
    tr_r[v] = tr_r[u];
    tr_size[v] = tr_size[u];
    tr_val[v] = tr_val[u];
    return v;
}

inline void pushup(int u) {
    if (u) {
        tr_size[u] = 1 + tr_size[tr_l[u]] + tr_size[tr_r[u]];
    }
}

void split(int u, int k, int &x, int &y) {
    if (!u) {
        x = y = 0;
        return;
    }
    u = clone(u);
    int left_size = tr_size[tr_l[u]];
    if (left_size >= k) {
        y = u;
        split(tr_l[u], k, x, tr_l[y]);
        pushup(y);
    } else {
        x = u;
        split(tr_r[u], k - left_size - 1, tr_r[x], y);
        pushup(x);
    }
}

int merge(int x, int y) {
    if (!x || !y) return x ? clone(x) : clone(y);
    if (xorshift32() % (tr_size[x] + tr_size[y]) < (uint32_t)tr_size[x]) {
        x = clone(x);
        tr_r[x] = merge(tr_r[x], y);
        pushup(x);
        return x;
    } else {
        y = clone(y);
        tr_l[y] = merge(x, tr_l[y]);
        pushup(y);
        return y;
    }
}

int build(int l, int r) {
    if (l > r) return 0;
    int mid = l + (r - l) / 2;
    int u = ++node_cnt;
    tr_val[u] = mid;
    tr_l[u] = build(l, mid - 1);
    tr_r[u] = build(mid + 1, r);
    pushup(u);
    return u;
}

int get_first(int u) {
    while (tr_l[u]) {
        u = tr_l[u];
    }
    return tr_val[u];
}

int temp_cnt = 0;
int next_tr_l[400005];
int next_tr_r[400005];
int next_tr_size[400005];
int next_tr_val[400005];

int copy_tree(int u) {
    if (!u) return 0;
    int v = ++temp_cnt;
    next_tr_size[v] = tr_size[u];
    next_tr_val[v] = tr_val[u];
    next_tr_l[v] = copy_tree(tr_l[u]);
    next_tr_r[v] = copy_tree(tr_r[u]);
    return v;
}

void gc() {
    temp_cnt = 0;
    int new_root = copy_tree(root);
    for(int i = 1; i <= temp_cnt; ++i) {
        tr_l[i] = next_tr_l[i];
        tr_r[i] = next_tr_r[i];
        tr_size[i] = next_tr_size[i];
        tr_val[i] = next_tr_val[i];
    }
    node_cnt = temp_cnt;
    root = new_root;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    root = build(0, 2 * n + 1);

    vector<int> ans;
    ans.reserve(n);

    for (int i = n; i >= 1; --i) {
        if (node_cnt > MAX_NODES - 200000) {
            gc();
        }

        int x = a[i];
        int t1, t2, t3, t4, u1, u2;

        split(root, 2 * x, t1, t2);
        split(t1, x, t3, t4);
        int A_root = t4;

        split(root, 2 * n + 2 - x, u1, u2);
        int B_root = u1;

        root = merge(A_root, B_root);

        ans.push_back(get_first(root));
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}