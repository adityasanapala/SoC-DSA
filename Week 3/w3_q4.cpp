#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using vint = vector<int>;
using vpair = vector<pair<int, int>>;
string A, B;
string sA, sB;
int ans = 0;

template <typename T>
void vprint(const T& v) {
    for (const auto& i : v) { cout << i << " "; }
    cout << "\n";
}

template <typename T>
void pprint(const T& v) {
    for (const auto& i : v) { cout << i.first << " " << i.second << "\n"; }
    cout << "\n";
}

int main() {
    cin >> A >> B;

    // Edit String
    // Minimum no of operations required to do shit
    // First let us resolve the longest matching substring
    // for each step i take in the base// I am taking the smaller string as the base
    // I need to look for all the upcoming strings
    // I then simply can't act on the new array
    // I need to track, how many are between 2 matching strings
    // Such a pain in the ass
    // I need to keep solving simultaneously whenver I encounter 2 consecutive matches
    // what should I do in between

    int a = 0, b = 0;  // the 2 pointers
    while (a < A.size() && b < B.size()) {
        if (A[a] == B[b]) {
            a++;
            b++;
            ans += max(sA.size(), sB.size());
            sA.clear();
            sB.clear();
        }
        else {
            int j = b;
            while (j < B.size()) {}
        }
        // this is if I find one
        // wha twill guarantee that I'll find one soon
        // If I encounter anything before the first match
        // keeep storing them for final termination
    }
    cout << ans << endl;
}
