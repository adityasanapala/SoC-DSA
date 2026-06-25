#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    vector<int> M(N);

    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    vector<vector<int>> hall(K + 1, vector<int>(K + 1, 0));

    int center = (K + 1) / 2;

    for (int req = 0; req < N; req++) {

        int m = M[req];

        long long bestCost = 1e18;

        int bestRow = -1;
        int bestL = -1;
        int bestR = -1;

        for (int row = 1; row <= K; row++) {

            for (int start = 1; start + m - 1 <= K; start++) {

                int end = start + m - 1;

                bool freeSeats = true;

                for (int seat = start; seat <= end; seat++) {

                    if (hall[row][seat]) {
                        freeSeats = false;
                        break;
                    }
                }

                if (!freeSeats)
                    continue;

                long long cost = 0;

                for (int seat = start; seat <= end; seat++) {

                    cost += abs(row - center);
                    cost += abs(seat - center);
                }

                if (cost < bestCost) {

                    bestCost = cost;
                    bestRow = row;
                    bestL = start;
                    bestR = end;
                }
                else if (cost == bestCost) {

                    if (row < bestRow) {

                        bestRow = row;
                        bestL = start;
                        bestR = end;
                    }
                    else if (row == bestRow && start < bestL) {

                        bestL = start;
                        bestR = end;
                    }
                }
            }
        }

        if (bestRow == -1) {

            cout << -1 << '\n';
        }
        else {

            cout << bestRow << " "
                 << bestL << " "
                 << bestR << '\n';

            for (int seat = bestL; seat <= bestR; seat++) {
                hall[bestRow][seat] = 1;
            }
        }
    }

    return 0;
}