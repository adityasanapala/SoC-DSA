#include <bits/stdc++.h>
using namespace std;

int main() {
    double x1, y1, r1;
    double x2, y2, r2;
    double x3, y3, r3;

    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    cin >> x3 >> y3 >> r3;

    double d = 2 * (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));

    if (fabs(d) < 1e-9) return 0;

    double ux =
        ((x1*x1 + y1*y1)*(y2-y3) +
         (x2*x2 + y2*y2)*(y3-y1) +
         (x3*x3 + y3*y3)*(y1-y2)) / d;

    double uy =
        ((x1*x1 + y1*y1)*(x3-x2) +
         (x2*x2 + y2*y2)*(x1-x3) +
         (x3*x3 + y3*y3)*(x2-x1)) / d;

    cout << fixed << setprecision(5) << ux << " " << uy << "\n";
    return 0;
}