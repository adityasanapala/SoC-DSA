#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> lastSeen;

    int left = 0;
    int answer = 0;

    for (int right = 0; right < n; right++) {
        int song;
        cin >> song;

        if (lastSeen.count(song) && lastSeen[song] >= left) {
            left = lastSeen[song] + 1;
        }

        lastSeen[song] = right;

        int currentLength = right - left + 1;

        if (currentLength > answer) {
            answer = currentLength;
        }
    }

    cout << answer << '\n';

    return 0;
}
