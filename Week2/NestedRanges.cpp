#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to hold range data and track its original index
struct Range {
    int x, y, id;
    bool operator()(const Range& a, const Range& b) {
        if (a.x == b.x) {
            return a.y > b.y; // Descending by y if x is equal
        }
        return a.x < b.x; // Ascending by x
    }
};

// Fenwick Tree (Binary Indexed Tree)
struct FenwickTree {
    int size;
    vector<int> tree;
    FenwickTree(int n) : size(n), tree(n + 1, 0) {}

    void update(int i, int delta) {
        for (; i <= size; i += i & -i) tree[i] += delta;
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }

    int query_range(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Range> ranges(n);
    vector<int> vals; // For coordinate compression of y

    for (int i = 0; i < n; i++) {
        cin >> ranges[i].x >> ranges[i].y;
        ranges[i].id = i;
        vals.push_back(ranges[i].y);
    }

    // Coordinate compression on y-coordinates
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    auto get_compressed_y = [&](int y) {
        return lower_bound(vals.begin(), vals.end(), y) - vals.begin() + 1;
    };

    // Sort ranges using our custom comparator
    sort(ranges.begin(), ranges.end(), Range());

    vector<int> contains(n, 0);
    vector<int> contained_by(n, 0);
    
    int max_compressed_val = vals.size();
    FenwickTree bit(max_compressed_val);

    // 1. Calculate how many other ranges it contains (Right to Left loop)
    for (int i = n - 1; i >= 0; i--) {
        int comp_y = get_compressed_y(ranges[i].y);
        contains[ranges[i].id] = bit.query(comp_y);
        bit.update(comp_y, 1);
    }

    // Reset Fenwick tree for the second pass
    fill(bit.tree.begin(), bit.tree.end(), 0);

    // 2. Calculate how many other ranges contain it (Left to Right loop)
    for (int i = 0; i < n; i++) {
        int comp_y = get_compressed_y(ranges[i].y);
        contained_by[ranges[i].id] = bit.query_range(comp_y, max_compressed_val);
        bit.update(comp_y, 1);
    }

    // Print results in the original input order
    for (int i = 0; i < n; i++) {
        cout << contains[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << contained_by[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}