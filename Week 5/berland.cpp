#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    long long d[n+1][n+1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }

    int k;
    cin >> k;

    while(k--){
        int u, v;
        long long w;

        cin >> u >> v >> w;

        long long sum = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][u] + w + d[v][j] < d[i][j]) {
                    d[i][j] = d[i][u] + w + d[v][j];
                }
                if (d[i][v] + w + d[u][j] < d[i][j]) {
                    d[i][j] = d[i][v] + w + d[u][j];
                }

                if (i < j) {
                    sum += d[i][j];
                }
            }
        }

        cout << sum << ' ';
    }

    cout << endl;

    return 0;
}