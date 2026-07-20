#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<int>;
map<int, int> M;

template <typename T>
void vprint(T& V) {
    for (auto& i : V) { cout << i << " "; }
    cout << "\n";
}

template <typename T>
void pprint(T& P) {
    for (auto& i : P) { cout << i.first << " " << i.second << "\n"; }
}

int main() {
    int n, l, r;
    int ans = 1;
    cin >> n;
    vint V(n);
    for (int i = 0; i < n; i++) { cin >> V[i]; }
    l = -1;
    for (int r = 0; r < n; r++) {
        int a = V[r];
        // printf("printing M\n");
        // pprint(M);
        // printf("before\n");
        // printf("a:%i\n", a);
        // printf("ans:%i, l:%i, r:%i\n", ans, l, r);
        if (M.find(a) == M.end()) {  // this means that a is not present in M
            // printf("upper\n");
            M[a] = r;
            ans = max(ans, r - l);
        }  // I am leaving l where it was
        else {
            // printf("lower\n");
            l = max(l, M[a]);
            M[a] = r;
        }
        ans = max(ans, r - l);
        // printf("after\n");
        // printf("ans:%i, l:%i, r:%i\n", ans, l, r);
        // printf("\n");
    }
    cout << ans << endl;
}
