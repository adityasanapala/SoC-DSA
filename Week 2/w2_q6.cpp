#include <iostream>
#include <algorithm>
using namespace std;

int main() {  
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int pos[n + 1];
        for (int i = 0; i < n; i++) {
            int v; cin >> v;
            pos[v] = i;
        }

        int best = 0;
        int start = 1, Len = 1;
        
        auto tryRun = [&](int l, int len) {
            int lo = max(l, n + 2 - l - len);
            if (lo * 2 <= n + 1) {
                int hi = n + 1 - lo;
                if (hi <= l + len - 1) {
                    best = max(best, hi - lo + 1);
                }
            }
        };
        
        for (int i = 2; i <= n; i++) {
            if (pos[i] > pos[i - 1]) {
                Len++;
            } else {
                tryRun(start, Len);
                start = i;
                Len = 1;
            }
        }
        tryRun(start, Len);
        
        cout << (n - best) / 2 << "\n";
    }
    return 0;
}