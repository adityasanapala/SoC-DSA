#include <iostream>
#include<string>
using namespace std;

const int MAX = 400005;
int pi[MAX]; 

void prefix(const string &s) {
    int n = s.size();
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
}

bool contains(const string &i, const string &j) {
    if (j.size() > i.size()) return false;
    string combo = j + "#" + i; 
    prefix(combo);
    int n = combo.size();
    for (int i = 0; i < n; i++) {
        if (pi[i] == (int)j.size()) return true;
    }
    return false;
}

int overlap(const string &a, const string &b) {
    string combo = b + "#" + a;
    prefix(combo);
    return pi[combo.size() - 1]; 
}

string merge(const string &a, const string &b) {
    if (contains(a, b)) return a; 
    if (contains(b, a)) return b; 
    int k = overlap(a, b);
    return a + b.substr(k); 
}

int main() {
    string s[3];
    cin >> s[0] >> s[1] >> s[2];

    int orders[6][3] = {
        {0,1,2}, {0,2,1}, {1,0,2},
        {1,2,0}, {2,0,1}, {2,1,0}
    };

    int best = -1;
    for (int o = 0; o < 6; o++) {
        string a = s[orders[o][0]];
        string b = s[orders[o][1]];
        string c = s[orders[o][2]];

        string ab  = merge(a, b);
        string abc = merge(ab, c);

        if (best == -1 || (int)abc.size() < best) best = abc.size();
    }

    cout << best << "\n";
    return 0;
}