#include <bits/stdc++.h>
using namespace std;

bool isRXCY(const string &s) {
    if (s.empty() || s[0] != 'R') return false;

    int i = 1;
    while (i < (int)s.size() && isdigit(s[i])) i++;

    if (i == 1 || i == (int)s.size() || s[i] != 'C') return false;

    for (int j = i + 1; j < (int)s.size(); j++) {
        if (!isdigit(s[j])) return false;
    }

    return true;
}

string colToExcel(int col) {
    string res;

    while (col > 0) {
        col--;
        res.push_back('A' + col % 26);
        col /= 26;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        if (isRXCY(s)) {
            int pos = s.find('C');

            int row = stoi(s.substr(1, pos - 1));
            int col = stoi(s.substr(pos + 1));

            cout << colToExcel(col) << row << '\n';
        } else {
            string colPart, rowPart;

            int i = 0;
            while (i < (int)s.size() && isalpha(s[i])) {
                colPart += s[i];
                i++;
            }

            rowPart = s.substr(i);

            // WRONG conversion for columns like AA, AB, BA, ...
            int col = 0;
            for (char c : colPart) {
                col = col * 26 + (c - 'A' + 1);
            }

            cout << "R" << rowPart << "C" << col << '\n';
        }
    }

    return 0;
}