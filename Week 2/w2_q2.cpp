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

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int cur = arr[left].val + arr[right].val;

        if (cur == x) {
            cout << arr[left].qwer << " " << arr[right].qwer << "\n";
            return 0;
        } 
        else if (cur < x) {
            left++;
        } 
        else {
            right--;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}