#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> a(n);
    for (auto &x : a) scanf("%d", &x);

    unordered_map<int, int> cnt;
    int distinct = 0, left = 0, bl = 0, br = 0, best = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[a[i]]++ == 0) distinct++;
        while (distinct > k) {
            if (--cnt[a[left]] == 0) distinct--;
            left++;
        }
        if (i - left + 1 > best) {
            best = i - left + 1;
            bl = left;
            br = i;
        }
    }
    printf("%d %d\n", bl + 1, br + 1);
    return 0;
}
