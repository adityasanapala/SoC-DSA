#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    string a, b;
    cin >> a >> b; 
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dis(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < 1+n; i++) {
        dis[i][0] = i; 
    }
    for (int j = 0; j < 1+m; j++) {
        dis[0][j] = j;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dis[i][j] = dis[i - 1][j - 1];
            } else {
                dis[i][j] = 1 + min({
                    dis[i][j - 1],   
                    dis[i - 1][j],   
                    dis[i - 1][j - 1]
                });
            }
        }
    }
    cout<<dis[n][m]<< "\n";
    return 0;
}