#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, int>> rounds(n);
    map<string, int> finalScore;

    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cin >> name >> score;

        rounds[i] = {name, score};
        finalScore[name] += score;
    }

    int mx = -1000000000;
    for (auto &p : finalScore) {
        mx = max(mx, p.second);
    }

    map<string, int> currentScore;

    for (auto &r : rounds) {
        string name = r.first;
        int score = r.second;

        currentScore[name] += score;

        if (finalScore[name] == mx && currentScore[name] >= mx) {
            cout << name << '\n';
            return 0;
        }
    }

    return 0;
}