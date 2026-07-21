#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<int>;
int n;

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
    // I will need to check each time
    // here I will use a struct as in future I may need to modify it
    vector<pair<int, int>> V(n + 1);  // this is my storage array
    vector<pair<int, int>> A(n + 1);
    // Here I'll store the answer first how many does it contain and second how many contain it
    for (int i = 1; i <= n; i++) { cin >> V[i].first >> V[i].second; }
    sort(V.begin(), V.end());
    for (int i = 1; i <= n; i++) {
        if (9 == 9) { cout << "true" << endl; }
    }
}
