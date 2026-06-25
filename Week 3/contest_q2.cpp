#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int c = (K + 1) / 2;
    bool occ[K+1][K+1];
    for(int i=1;i<=K;i++){
        for(int j=1;j<=K;j++){
            occ[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++) {

        int M;
        cin >> M;

        int bestcost = 1e9;
        int bestrow = -1;
        int bestleft = -1;

        for (int r = 1; r <= K; r++) {
            for (int l = 1; l + M - 1 <= K; l++) {
                int z = l + M - 1;
                bool ok = true;
                for (int x = l; x <= z; x++) {
                    if (occ[r][x]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue;
                int cost = 0;
                for (int y = l; y <= z; y++) {
                    cost += abs(r - c);
                    cost += abs(y - c);
                }

                // choose best
                if (bestrow == -1 ||
                    cost < bestcost ||
                    (cost == bestcost && r < bestrow) ||
                    (cost == bestcost && r == bestrow && l < bestleft)) {

                    bestcost = cost;
                    bestrow = r;
                    bestleft = l;
                }
            }
        }

        if (bestrow == -1) {
            cout << -1 << "\n";
        } else {
            int z = bestleft + M - 1;

            // mark occupied
            for (int j = bestleft; j <= z; j++) {
                occ[bestrow][j] = true;
            }

            cout << bestrow << " " << bestleft << " " << z << "\n";
        }
    }

    return 0;
}