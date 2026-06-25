#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int freq[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int noOfDistinctNumbers = 0;
    int left = 0, ans = 0;
    int best_left = 1, best_right = 1;

    for (int right = 0; right < n; right++) {
        if (freq[a[right]] == 0) {
            noOfDistinctNumbers++;
        }
        freq[a[right]]++;

        while (noOfDistinctNumbers > k) {
            freq[a[left]]--;
            if (freq[a[left]] == 0) {
                noOfDistinctNumbers--;
            }
            left++;
        }

        if (right - left + 1 > ans) {
            ans = right - left + 1;
            best_left = left + 1;
            best_right = right + 1;
        }
    }

    cout << best_left << " " << best_right << "\n";

    return 0;
}