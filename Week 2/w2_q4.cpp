#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int q[n];
    int head = 0;
    int tail = 0;

    int ans_size = n - k + 1;
    int ans[ans_size];
    int ans_idx = 0;

    for (int i = 0; i < n; i++) {
        if (head < tail && q[head] < i - k + 1) {
            head++;
        }

        while (head < tail && nums[q[tail - 1]] <= nums[i]) {
            tail--;
        }

        q[tail] = i;
        tail++;

        if (i >= k - 1) {
            ans[ans_idx] = nums[q[head]];
            ans_idx++;
        }
    }

    for (int i = 0; i < ans_size; i++) {
        cout << ans[i] << (i == ans_size - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}