#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using vint = vector<int>;

void vprint(vint& v) {
    for (int i : v) { cout << i << " "; }
    cout << "\n";
}

int main() {
    int n;
    int ans = 1;
    cin >> n;  // n>=1
    vint v(n);
    for (int i = 0; i < n; i++) { cin >> v[i]; }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++) {
        if (v[i] != v[i - 1]) { ans++; }
    }
    cout << ans << endl;
}
