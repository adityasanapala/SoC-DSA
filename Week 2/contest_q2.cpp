#include <iostream>
#include <string>
using namespace std;

int main() {
    int n=0;
    string a[1000];
    string s;
    while(getline(cin,s)){
        a[n]=s;
        n++;
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, (int)a[i].size());
    }
    string border(mx + 2, '*');
    cout << border << '\n';

    bool leftTurn = true;

    for (int i=0;i<n;i++) {
        int diff = mx - (int)a[i].size();

        int left, right;

        if (diff % 2 == 0) {
            left = right = diff / 2;
        } else {
            if (leftTurn) {
                left = diff / 2;
                right = diff / 2 + 1;
            } else {
                left = diff / 2 + 1;
                right = diff / 2;
            }
            leftTurn = !leftTurn;
        }

        cout << '*'
             << string(left, ' ')
             << a[i]
             << string(right, ' ')
             << "*\n";
    }

    cout << border << '\n';
    return 0;
}