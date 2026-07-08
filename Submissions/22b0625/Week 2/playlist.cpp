#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<long long, int> last;
    int left = 0;
    int ans = 0;

    for (int right = 0; right < n; right++) {
        if (last.count(a[right])) {
            left = max(left, last[a[right]] + 1);
        }

        last[a[right]] = right;
        ans = max(ans, right - left + 1);
    }

    cout << ans << '\n';

    return 0;
}