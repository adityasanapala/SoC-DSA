#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<int>;
int n, ans = 1;
map<int, int> M;

template <typename T>
void vprint(T& V) {
    for (auto& i : V) { cout << i << " "; }
    cout << "\n";
}

template <typename T>
void pprint(T& P) {
    for (auto& i : P) { cout << i.first << " " << i.second << "\n"; }
    cout << "\n";
}

int main() {
    cin >> n;
    vint V(n);
    for (int i = 0; i < n; i++) { cin >> V[i]; }
    M[V[0]] = 0;
    for (int i = 1; i < n; i++) {
        int a = V[i];
        if (M.find(a) != M.end()) { ans = max(ans, ans - M[a]); }
        else {
            for (auto& j : M) {
                if (j.second <= a) { M.erase(i); }
            }
            M[a] = i;
            ans++;
            // Yes I need to maintain l and r just as the guy solved it
        }
    }
    // here I forgot to erase all the entries below the set value
    // I need to set another loop here to reset the erase/remove the values
    // erasing all the values with it being less than
    // I could have dry ran
    // Can i keep popping element while looping
    cout << ans << endl;
}
