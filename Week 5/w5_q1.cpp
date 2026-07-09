#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    int n = (int)s.size();

    stack<int> st;
    st.push(-1);

    int best = 0;
    long long cnt = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                int len = i - st.top();
                if (len > best) {
                    best = len;
                    cnt = 1;
                } else if (len == best) {
                    cnt++;
                }
            }
        }
    }

    if (best == 0) cout << "0 1\n";
    else cout << best << ' ' << cnt << '\n';

    return 0;
}
