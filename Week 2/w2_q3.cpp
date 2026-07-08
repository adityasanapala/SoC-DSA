#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    scanf("%d %lld", &n, &x);

    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i].first);
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1;
        long long need = x - a[i].first;
        while (l < r) {
            long long s = a[l].first + a[r].first;
            if (s == need) {
                printf("%d %d %d\n", a[i].second, a[l].second, a[r].second);
                return 0;
            }
            if (s < need) l++;
            else r--;
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}
