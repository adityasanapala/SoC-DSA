#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long getMin(vector<long long>& a,vector<long long>& merged,int& i,int& j,int n) {
    if (i < n && (j >= (int)merged.size() || a[i] <= merged[j])) {
        return a[i++];
    }
    return merged[j++];
}
int main() {
    int x, n;
    cin >> x >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> merged;
    int i = 0, j = 0;

    long long ans = 0;

    for (int k = 0; k < n - 1; k++) {
        long long u = getMin(a, merged, i, j, n);
        long long v = getMin(a, merged, i, j, n);

        long long s = u + v;
        ans += s;

        merged.push_back(s);
    }

    cout << ans << '\n';
}