#include <iostream>
#include <algorithm>

using namespace std;

struct Range {
    int x, y, id;
};

bool comp(Range a, Range b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y > b.y;
}

int qwer[200005];
int n;

void update(int idx, int val) {
    while (idx <= n) {
        qwer[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += qwer[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int main() {
    cin >> n;

    Range r[n];
    int ys[n];
    
    for (int i = 0; i < n; i++) {
        cin >> r[i].x >> r[i].y;
        r[i].id = i;
        ys[i] = r[i].y;
    }

    sort(ys, ys + n);
    int uniqy = unique(ys, ys + n) - ys;
    for (int i = 0; i < n; i++) {
        r[i].y = lower_bound(ys, ys + uniqy, r[i].y) - ys + 1;
    }

    sort(r, r + n, comp);

    int contains[n];
    int contained_by[n];

    for (int i = 0; i <= n; i++) qwer[i] = 0;
    for (int i = n - 1; i >= 0; i--) {
        contains[r[i].id] = query(r[i].y);
        update(r[i].y, 1);
    }

    for (int i = 0; i <= n; i++) qwer[i] = 0;
    for (int i = 0; i < n; i++) {
        contained_by[r[i].id] = query(n) - query(r[i].y - 1);
        update(r[i].y, 1);
    }

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