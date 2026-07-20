#include <iostream>
#include <string>
using namespace std;
int ans = 0;
string A = "geeks";  // length m
string B = "greek";  // length n
int m = A.size();
int n = B.size();

// First of all why have I increase from
int fun(int i, int j) {
    if (i == -1 || j == -1) { return 0; }
    int shit = max(ans, fun(i - 1, i - j) + 1);
    if (A[i] == B[j]) {
        ans = shit;
        return shit;
    }
    else { return fun(i - 1, i - j); }
}

int main() {
    // ans = 3
    // I am looking for each pair means
    // I am effectively looping over 2d numbers
    // meaning I am looping over i and then j
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i] == B[j]) { ans++; }
        }
        // Even if the length increase as I go towards righht
        // I am just looping randomly and storing the mas of all the answers encountered so far
    }
    cout << ans << endl;
}
