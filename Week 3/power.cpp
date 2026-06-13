#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, p1, p2, p3, t1, t2;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;

    int l[n], r[n];
    
    int power = 0;

    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        power += (r[i] - l[i]) * p1;
    }

    for (int i = 0; i < n - 1; ++i) {
        int gap = l[i + 1] - r[i];

        int tp1 = min(gap, t1);
        power += tp1 * p1;
        gap -= tp1;

        int tp2 = min(gap, t2);
        power += tp2 * p2;
        gap -= tp2;

        power += gap * p3;
    }

    cout << power << endl;

    return 0;
    
}