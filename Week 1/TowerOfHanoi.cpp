#include <iostream>
#include <vector>
using namespace std;
using vint = vector<int>;

// void vprint(vint& v) {
//     for (int& i : v) { cout << i << " "; }
//     cout << "\n";
// }

void vprint(vector<pair<int, int>>& v) {
    for (auto& i : v) { cout << i.first << " " << i.second << endl; }
}

void pprint(pair<int, int>& p) { cout << p.first << " " << p.second << endl; }

int fun(int n, vector<pair<int, int>>& v) {
    if (n == 1) { return 1; }
    int len = v.size();
    for (auto& i : v) {
        // i is the pair that v contains
        // cout << "before exchange" << endl;
        // pprint(i);
        if (i.first == 2) {
            i.first = 3;
        } else if (i.first == 3) {
            i.first = 2;
        }
        if (i.second == 2) {
            i.second = 3;
        } else if (i.second == 3) {
            i.second = 2;
        }
        // cout << "after exchange" << endl;
        // pprint(i);
    }

    // I have changed that in inplace
    // why am I giving input to the arrays in the decreasing size, I need to receive vectors from the
    // smaller functions

    v.push_back({1, 3});
    for (int j = 0; j < len; j++) {
        // i is the pair that v contains
        // cout << "before exchange" << endl;
        // pprint(i);
        pair<int, int> i = v[j];
        if (i.first == 1) {
            i.first = 2;
        } else if (i.second == 1) {
            i.second = 2;
        }
        if (i.first == 3) {
            i.first = 1;
        } else if (i.second == 3) {
            i.second = 1;
        }
        if (i.first == 2) {
            i.first = 3;
        } else if (i.second == 2) {
            i.second = 3;
        }
        v.push_back(i);
        // cout << "after exchange" << endl;
        // pprint(i);
    }
    v.pop_back();
    // now I need to copy push_back all the elements
    // I can first take the length and then after pushing {1,3}
    // I can take the length of the vector when it is read first time and then
    // till then I can push back once again
    return (2 * fun(n - 1, v) + 1);
    // Each time a recursive call is made, I am just appending the stuff. Actually which disk is it carries
    // no info. It is just how many times the function is called
}
// I need to write all the possible moves as well
// i.e just repeat the moves for the last except just switch the columns being used from 2 to 3 and from 3 to 2
// I need to make a vector of pairs
// Or simply maintain a map
// Actually no, in maps keys need to be unique
// and keep modifying the vector itself after each iteration/recursion
// COLDPLAY : GOAT : best band
// listen to its song while studying

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v = {{1, 3}};
    // I am passing by address and hence
    // why didn't it switch 3 from 3 to 2.
    cout << fun(n, v) << endl;
    vprint(v);
}
