#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int k;
        scanf("%d", &k);
        vector<long long> c(k);
        long long S = 0;
        for (int i = 0; i < k; i++) {
            scanf("%lld", &c[i]);
            S += c[i];
        }

        vector<long long> terms;
        terms.push_back(1);
        terms.push_back(1);
        long long sum = 2;
        bool exact = false;
        if (S == 1) {
            terms.assign(1, 1);
            exact = true;
        } else if (S == 2) {
            exact = true;
        } else {
            while (sum < S) {
                long long nx = terms[terms.size() - 1] + terms[terms.size() - 2];
                terms.push_back(nx);
                sum += nx;
            }
            exact = (sum == S);
        }

        if (!exact) {
            printf("NO\n");
            continue;
        }

        priority_queue<pair<long long, int>> pq;
        for (int i = 0; i < k; i++) pq.push({c[i], i});

        int prev = -1;
        bool ok = true;
        for (int bi = (int)terms.size() - 1; bi >= 0 && ok; bi--) {
            long long need = terms[bi];
            if (pq.empty()) { ok = false; break; }
            pair<long long, int> top = pq.top(); pq.pop();
            pair<long long, int> stash(-1, -1);
            if (top.second == prev) {
                if (pq.empty()) { ok = false; break; }
                stash = top;
                top = pq.top(); pq.pop();
            }
            top.first -= need;
            if (top.first < 0) { ok = false; break; }
            prev = top.second;
            if (top.first > 0) pq.push(top);
            if (stash.second != -1) pq.push(stash);
        }

        printf(ok ? "YES\n" : "NO\n");
    }
    return 0;
}
