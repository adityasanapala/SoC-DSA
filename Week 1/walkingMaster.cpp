#include <iostream>
#include <vector>
using namespace std;
using vint = vector<int>;

void vprint(vint& v) {
    for (int& i : v) { cout << i << " "; }
    cout << "\n";
}

/*
That is, if she is standing on point (x,y), she can either move to point (x+1,y+1) or point (x−1,y).
YunQian initially stands at point (a,b) and wants to move to point (c,d). Find the minimum number of moves she needs to
make or declare that it is impossible.
*/

// I can combine these movements to create various new movements
// firsr of all I y cannot reduce

// move 1 : (+1, +1 )  n times
// move 2 : (-1, nil)  m times
// dx = n - m
// dy = n
// if fo rsome pair of n and m, I can satisfy
// c = a + n - m  __i
// d = b + n      __ii
// subtracting eqn i from ii, I get the value o

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int m = d + a - b - c;
        int n = d - b;
        if (m >= 0 and n >= 0) {
            cout << m + n << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
