#include <iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stack<int> st;
    st.push(-1);

    int best = 0;
    int cnt = 1;

    for (int i = 0; i < (int)s.size(); i++) {
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

    if (best == 0)
        cout << "0 1\n";
    else
        cout << best << " " << cnt << "\n";

    return 0;
}