#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (auto &x : a) scanf("%d", &x);

    unordered_map<int, int> last;
    int best = 0, start = 0;
    for (int i = 0; i < n; i++) {
        auto it = last.find(a[i]);
        if (it != last.end() && it->second >= start) start = it->second + 1;
        last[a[i]] = i;
        best = max(best, i - start + 1);
    }
    printf("%d\n", best);
    return 0;
}
