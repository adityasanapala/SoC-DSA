#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> moves;

void towerOfHanoi(int n, int left, int middle, int right) {

    // base case
    if(n == 1) {
        moves.push_back({left, right});
        return;
    }

    // move n-1 disks from left to middle
    towerOfHanoi(n - 1, left, right, middle);

    // move biggest disk from left to right
    moves.push_back({left, right});

    // move n-1 disks from middle to right
    towerOfHanoi(n - 1, middle, left, right);
}

int main() {

    int n;
    cin >> n;

    towerOfHanoi(n, 1, 2, 3);

    cout << moves.size() << endl;

    for(auto p : moves) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}