#include <bits/stdc++.h>
using namespace std;

bool leftExtra = true;

void printline(string s, int maxi) {
    cout << "*";

    int spaces = maxi - s.size();

    int left, right;

 if (spaces % 2 == 0) {
    left = right = spaces / 2;
}
else {
    if (leftExtra) {
        left = spaces / 2;
        right = spaces / 2 + 1;
    }
    else {
        left = spaces / 2 + 1;
        right = spaces / 2;
    }

    leftExtra = !leftExtra;
}

    for (int k = 0; k < left; k++) {
        cout << " ";
    }

    cout << s;

    for (int k = 0; k < right; k++) {
        cout << " ";
    }

    cout << "*" << endl;
}

int main() {

    vector<string> lines;
    string s;

    while (getline(cin, s)) {
        lines.push_back(s);
    }

    int maxi = 0;

    for (string &x : lines) {
        maxi = max(maxi, (int)x.size());
    }

    for (int i = 0; i < maxi + 2; i++) {
        cout << "*";
    }
    cout << endl;

    for (string &x : lines) {
        printline(x, maxi);
    }

    for (int i = 0; i < maxi + 2; i++) {
        cout << "*";
    }
    cout << endl;

    return 0;
}