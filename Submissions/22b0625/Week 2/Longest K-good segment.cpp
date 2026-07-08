#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> freq;

    int l = 0;
    int distinct = 0;

    int bestL = 0;
    int bestR = 0;

    for (int r = 0; r < n; r++) {
        if (freq[a[r]] == 0) {
            distinct++;
        }

        freq[a[r]]++;

        while (distinct > k) {
            freq[a[l]]--;

            if (freq[a[l]] == 0) {
                distinct--;
            }

            l++;
        }

        if (r - l > bestR - bestL) {
            bestL = l;
            bestR = r;
        }
    }

    cout << bestL + 1 << " " << bestR + 1 << '\n';

    return 0;
}