#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        map<int, int> ending;

        int sets = 0;

        for (int x : a) {

            if (ending[x - 1] > 0) {

                ending[x - 1]--;
                ending[x]++;

            } else {

                sets++;
                ending[x]++;
            }
        }

        cout << sets << '\n';
    }

    return 0;
}