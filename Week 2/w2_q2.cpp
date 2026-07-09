#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    scanf("%d %lld", &n, &x);

    unordered_map<long long, int> seen;
    for (int i = 1; i <= n; i++) {
        long long a;
        scanf("%lld", &a);
        auto it = seen.find(x - a);
        if (it != seen.end()) {
            printf("%d %d\n", it->second, i);
            return 0;
        }
        seen[a] = i;
    }
    printf("IMPOSSIBLE\n");
    return 0;
}
