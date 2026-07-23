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
    cout << "\n";
}

// this time I will use 1 based indexing
int main() {
    int n, l, r;
    cin >> n;
    vint V(n + 1);
    for (int i = 1; i <= n; i++) { cin >> V[i]; }
    l = 1;
    for (int r = 1; r <= n; r++) {
        int a = V[r];
        if (M[a] == 0) {}
        // means I was unable to find that number simply assign M[a] = r and get the answer
        // Here I need to clarify one thing l is the position on which I have the last repetion
        // and therefore I need to remove l as well ans hence it will start from l =0
    }
}
