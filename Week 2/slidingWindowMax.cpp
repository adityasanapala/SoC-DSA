#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

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

int mmax(vector<int>& V, int st, int end) {
    int ans = V[st];
    for (int i = st; i < end; i++) { ans = max(ans, V[i]); }
    return ans;
}

vector<int> maxSlidingWindow(vector<int>& V, int k) {
    vector<int> ans;
    for (int i = 0; i <= V.size() - k; i++) { ans.push_back(mmax(V, i, i + k)); }
    return ans;
}

int main() {}
