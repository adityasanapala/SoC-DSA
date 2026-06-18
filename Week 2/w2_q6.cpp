#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> pos(n + 2);
        for (int i = 1; i <= n; i++) {
            int p;
            scanf("%d", &p);
            pos[p] = i;
        }
        int l, r, cnt = 0;
        if (n % 2 == 0) {
            l = n / 2;
            r = n / 2 + 1;
            if (pos[l] < pos[r]) {
                cnt = 1;
                while (l > 1 && r < n && pos[l - 1] < pos[l] && pos[r] < pos[r + 1]) {
                    l--;
                    r++;
                    cnt++;
                }
            }
        } else {
            l = (n + 1) / 2;
            r = l;
            while (l > 1 && r < n && pos[l - 1] < pos[l] && pos[r] < pos[r + 1]) {
                l--;
                r++;
                cnt++;
            }
        }
        printf("%d\n", n / 2 - cnt);
    }
    return 0;
}
