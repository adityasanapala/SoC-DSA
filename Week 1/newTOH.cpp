#include <iostream>
#include <vector>
using namespace std;
using vint = vector<int>;

void vprint(vint& v) {
    for (int i : v) { cout << i << " "; }
    cout << "\n";
}

int fun(int n) {
    if (n == 1) { return 1; }
    return (2 * fun(n - 1) + 1);
}

vector<pair<int, int>> gun(vector<pair<int, int>>& v) {
    vector<pair<int, int>> ans;
    int len = v.size();
    if (len == 1) { return {{1, 3}}; }
    // I need to append a vector to a vector with different sets of {st,md,end}
    // every time I am pushing back, I'll redeclare {st,md,end}
    // but I need to return with the values of st, md, end so that I can know
    // Actaully I do not need to know
    // but how will I come to know which to swap and how
    // can i return a vector full of variables with fixed reference
    // so that I can modify them later
    return ans;
}

// I will maintain three varriables
// one begin other middle other end

int main() {
    int n;
    cin >> n;
    cout << fun(n) << endl;
}
