#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;
    map<long long, int> pos;

    for(int i = 1; i <= n; i++) {
        long long num;
        cin >> num;

        long long need=x-num;
        if(pos.count(need)){
            cout<<pos[need]<<" "<<i;
            return 0;
        }
        pos[num] = i;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}