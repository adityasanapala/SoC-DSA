#include <iostream>
#include <vector>
using namespace std;
using vint = vector<int>;

void vprint(vint& v) {
    for (int& i : v) { cout << i << " "; }
    cout << "\n";
}
// nth number of fibonnacci 0 1 1 2
int fibo(int n, vint& v) {
    if (v[n] == -1) { v[n] = (fibo(n - 1, v) + fibo(n - 2, v)); }
    return v[n];
}
// obviolsy this has too much overhead and repetition
// now I need to update the function so that before calling itself
// it checks in an array

int main() {
    int n = 13;
    vint v(n + 1, -1);
    v[0] = 0;
    v[1] = 1;
    cout << fibo(n, v) << endl;
    vprint(v);
}
