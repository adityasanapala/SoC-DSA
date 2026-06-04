#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {

        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        // cannot decrease y
        if(d < b) {
            cout << -1 << endl;
            continue;
        }

        long long upMoves = d - b;

        // x after all up-right moves
        long long newX = a + upMoves;

        // cannot move right afterwards
        if(newX < c) {
            cout << -1 << endl;
            continue;
        }

        long long leftMoves = newX - c;

        cout << upMoves + leftMoves << endl;
    }

    return 0;
}