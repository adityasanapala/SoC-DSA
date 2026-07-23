#include <iostream>
#include <vector>
using namespace std;
using vint = vector<int>;

void vprint(vint& v) {
    for (int i : v) { cout << i << " "; }
    cout << "\n";
}

// brute force:
//      loop through each number in between
//      and then loop through each number inside finding the samllest and largest
//          this will give runtime error for sure
// The thing is if the range is big enough, I will always 0 and 9
// both 9 and 0 will be present if the difference is greater than 100
// 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69
// If I have difference greater than 10 find the corresponding to nine and then the lowest
//  40 41 42 43 44 45 46 47 48
//  50 51 52 53 54 55 56 57 58
//  then the greates diff is toward one of the ends
//  as the difference grows towards both sides

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s, l;  // 1<=s<=l<=10^6
        cin >> s >> l;
    }
}
