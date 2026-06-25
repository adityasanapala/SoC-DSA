#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> prefix_function(const string& s) {
    vector<int> pi(s.size(), 0);

    for (int i = 1; i < (int)s.size(); i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;

        pi[i] = j;
    }

    return pi;
}

bool contains(const string& text, const string& pattern) {
    string t = pattern + "#" + text;
    vector<int> pi = prefix_function(t);

    int m = pattern.size();

    for (int x : pi) {
        if (x == m)
            return true;
    }

    return false;
}

string mergestrings(const string& a, const string& b) {
    if (contains(a, b))
        return a;

    if (contains(b, a))
        return b;

    string t = b + "#" + a;
    vector<int> pi = prefix_function(t);

    int overlap = pi.back();

    return a + b.substr(overlap);
}

string build(string a, string b, string c) {
    string ab = mergestrings(a, b);
    return mergestrings(ab, c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s[3];

    for (int i = 0; i < 3; i++)
        cin >> s[i];

    int ans = build(s[0], s[1], s[2]).size();

    ans = min(ans, (int)build(s[0], s[2], s[1]).size());
    ans = min(ans, (int)build(s[1], s[0], s[2]).size());
    ans = min(ans, (int)build(s[1], s[2], s[0]).size());
    ans = min(ans, (int)build(s[2], s[0], s[1]).size());
    ans = min(ans, (int)build(s[2], s[1], s[0]).size());

    cout << ans << '\n';

    return 0;
}