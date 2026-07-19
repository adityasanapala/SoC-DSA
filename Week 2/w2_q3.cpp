#include <iostream>
#include <algorithm>

using namespace std;

struct ELem {
    int val;
    int qwer;
};

bool comp(ELem a, ELem b) {
    return a.val < b.val;
}

int main() {
    int n, x;
    cin >> n >> x;

    ELem arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].val;
        arr[i].qwer = i + 1;
    }

    sort(arr, arr + n, comp);

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;
        int target = x - arr[i].val;

        while (left < right) {
            int cur = arr[left].val + arr[right].val;

            if (cur == target) {
                cout << arr[i].qwer << " " << arr[left].qwer << " " << arr[right].qwer << "\n";
                return 0;
            } 
            else if (cur < target) {
                left++;
            } 
            else {
                right--;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}