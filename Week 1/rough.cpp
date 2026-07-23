#include <iostream>
#include <vector>
using namespace std;
using vint = vector<int>;

void vprint(vint& v) {
    for (int i : v) { cout << i << " "; }
    cout << "\n";
}

int main() { cout << abs(-8) << endl; }
