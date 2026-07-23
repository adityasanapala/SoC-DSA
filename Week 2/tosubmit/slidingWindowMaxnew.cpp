#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<int>;
multiset<int> S;

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

vector<int> maxSlidingWindow(vector<int>& V, int k) {
    vector<int> ans;
    int st = 0;
    int end = 0;
    int n = V.size();
    while (end < k) {
        S.insert(V[end]);
        end++;
    }
    end--;
    while (end < n - 1) {
        ans.push_back(*(S.rbegin()));
        auto it = S.find(V[st]);
        if (it != S.end()) S.erase(it);
        st++;
        end++;
        S.insert(V[end]);
    }
    ans.push_back(*(S.rbegin()));
    return ans;
}

int main() {
    vint V = {7, 2, 4};
    int k = 2;
    vint ans = maxSlidingWindow(V, k);
    vprint(ans);
}
