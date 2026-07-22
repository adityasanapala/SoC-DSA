#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long x;
    cin >> n >> x;
    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 2; i++) {
        long long target = x - a[i].first;
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            long long current_sum = a[left].first + a[right].first;

            if (current_sum == target) {
                cout << a[i].second << " " << a[left].second << " " << a[right].second << "\n";
                return 0;
            } 
            else if (current_sum < target) {
                left++;
            } 
            else {
                right--;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
