        #include <iostream>
        #include <map>
        #include <algorithm>
        #include <map>
        #include <vector>
        #include <set>
        #include <math.h>
        #include <bits/stdc++.h>


        using namespace std;




void solve() {
    int n;
    cin >> n;


    vector<int> pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        pos[x] = i;
    }


    int l = (n + 1) / 2;            // Determining the center values
    int r = (n + 2) / 2;


    if (pos[l] > pos[r]) {
        cout << l << "\n";
        return;
    }


    int ans = l - 1;


    while (l > 1 && r < n) {
        if (pos[l - 1] < pos[l] && pos[r] < pos[r + 1]) {
            l--;
            r++;
            ans--;
        } else {
            break;
        }
    }

    cout << ans << "\n";
}

int main() {


    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
