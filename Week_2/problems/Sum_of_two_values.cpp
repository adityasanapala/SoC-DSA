#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element {
    long long val;
    int original_idx;
};

bool compareElements(const Element& a, const Element& b) {
    return a.val < b.val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;

    vector<Element> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].val;
        arr[i].original_idx = i + 1;
    }

    sort(arr.begin(), arr.end(), compareElements);

    for (int i = 0; i < n - 2; ++i) {
        if (arr[i].val + arr[i+1].val + arr[i+2].val > x) break;
        
        long long target = x - arr[i].val;
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            long long current_sum = arr[left].val + arr[right].val;

            if (current_sum == target) {
                cout << arr[i].original_idx << " " 
                     << arr[left].original_idx << " " 
                     << arr[right].original_idx << "\n";
                return 0;
            } else if (current_sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}