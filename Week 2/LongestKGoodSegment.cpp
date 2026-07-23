#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    unordered_map<int, int> mp;

    int left = 0;
    int l = 0, r = 0;

    for (int right = 0; right < n; right++) {
        mp[a[right]]++;

        while (mp.size() > k) {
            mp[a[left]]--;

            if (mp[a[left]] == 0)
                mp.erase(a[left]);

            left++;
        }

        if (right - left > r - l) {
            l = left;
            r = right;
        }
    }

    cout << l + 1 << " " << r + 1;
}