#include <iostream>
#include <string>
using namespace std;

// Returns length of the longest common suffix
// ending with the last characters
int commonSuffix(string& s1, string& s2, int m, int n) {
    if (m == 0 || n == 0 || s1[m - 1] != s2[n - 1]) return 0;
    return 1 + commonSuffix(s1, s2, m - 1, n - 1);
}
// this is not checking for all substrings less than the length of m and n
// It is checking
// if the index 0 then also it is returnign 0, but index==0 should be valid
// this condition is met ads this never explicitly calculates m but passes for m-1 and n-1
// now it checks for both being reduced by 1,
// and not all the cases
// but as I am looping through all possible pairs of i and j and each is looping till 0
// rreducing both by 1
// But I believe that it gives heavy repetition

int lcs(string& s1, string& s2) {
    int res = 0;
    // and take the maximum of all.
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) { res = max(res, commonSuffix(s1, s2, i, j)); }
    }
    return res;
}

int main() {
    string s1 = "GeeksforGeeks";
    string s2 = "GeeksQuiz";
    cout << lcs(s1, s2) << endl;
    return 0;
}
