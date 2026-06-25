#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> freq;

    int left = 0;
    int distinct = 0;

    int bestL = 0, bestR = 0;

    for (int right = 0; right < n; right++) {
        if (freq[a[right]] == 0)
            distinct++;

        freq[a[right]]++;

        while (distinct > k) {
            freq[a[left]]--;

            if (freq[a[left]] == 0)
                distinct--;

            left++;
        }

        if (right - left > bestR - bestL) {
            bestL = left;
            bestR = right;
        }
    }

    cout << bestL + 1 << " " << bestR + 1 << '\n';

    return 0;
}