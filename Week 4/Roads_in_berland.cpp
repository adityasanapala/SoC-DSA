#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> s(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> s[i][j];
        }
    }
    int k;
    cin >> k;
    vector<int> x(k), y(k), z(k);
    for (int i = 0; i < k; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
    }

    for (int a = 0; a < k; a++){
        int u = x[a] - 1;
        int v = y[a] - 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int path1 = s[i][u] + z[a] + s[v][j];
                int path2 = s[i][v] + z[a] + s[u][j];
                s[i][j] = min({s[i][j], path1, path2});
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                sum += s[i][j];
            }
        }
        cout << sum << " ";
    }
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
