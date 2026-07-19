#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int songs[n];
    for (int i = 0; i < n; i++) cin >> songs[i];

    int sort1[n];
    for (int i = 0; i < n; i++) sort1[i] = songs[i];
    sort(sort1, sort1 + n);
    int m = unique(sort1, sort1 + n) - sort1;

    int comp[n];
    for (int i = 0; i < n; i++)
        comp[i] = lower_bound(sort1, sort1 + m, songs[i]) - sort1;

    int ls[n];
    for (int i = 0; i < n; i++) ls[i] = -1;

    int max1 = 0, left = 0;
    for (int i = 0; i < n; i++) {
        int song = comp[i];

        if (ls[song] >= left)
            left = ls[song] + 1;

        ls[song] = i;
        max1 = max(max1, i - left + 1);
    }

    cout << max1 << "\n";
    return 0;
}