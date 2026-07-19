#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int m[n];
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    int c = (k + 1) / 2;

    bool is_empty[k + 1][k + 1];
    
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            is_empty[i][j] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        int qwer = m[i];
        int best = 1e9; 
        int best_row = -1, best_yl = -1, best_yr = -1;

        for (int x = 1; x <= k; x++) {
            for (int yl = 1; yl <= k - qwer + 1; yl++) {
                int yr = yl + qwer - 1;

                bool pos = true;
                for (int y = yl; y <= yr; y++) {
                    if (!is_empty[x][y]) {
                        pos = false;
                        break;
                    }
                }

                if (pos) {
                    int cur = 0;
                    for (int y = yl; y <= yr; y++) {
                        cur += abs(x - c) + abs(y - c);
                    }

                    if (cur < best) {
                        best = cur;
                        best_row = x;
                        best_yl = yl;
                        best_yr = yr;
                    }
                }
            }
        }

        if (best_row == -1) {
            cout << -1 << "\n";
        } else {
            cout << best_row << " " << best_yl << " " << best_yr << "\n";
            for (int y = best_yl; y <= best_yr; y++) {
                is_empty[best_row][y] = false; 
            }
        }
    }

    return 0;
}