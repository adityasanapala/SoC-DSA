#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < n; i++) {

        // Remove elements outside current window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove smaller elements from back
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // First complete window formed
        if (i >= k - 1) {
            ans.push_back(nums[dq.front()]);
        }
    }

    for (int x : ans) {
        cout << x << " ";
    }

    cout << '\n';

    return 0;
}