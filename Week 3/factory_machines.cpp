#include <bits/stdc++.h>
using namespace std;
int n;
long long t;
vector<long long> k;
long long products(long long given_time) {
    long long total_products = 0;
    for (int i = 0; i < n; i++) {
        total_products += (given_time / k[i]);
        if (total_products >= t) {
            return total_products;
        }
    }
    return total_products;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    long long max_time = 0;
    for (int i = 0; i < n; i++) {
        long long p;
        cin >> p;
        k.push_back(p);
        max_time = max(max_time, p);
    }
    long long left = 1;
    long long right = t * max_time;
    long long ans = right;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (products(mid) >= t) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}