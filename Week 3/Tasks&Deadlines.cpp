#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> tasks(n);

    for (int i = 0; i < n; i++)
        cin >> tasks[i].first >> tasks[i].second;

    sort(tasks.begin(), tasks.end());

    long long time = 0, ans = 0;

    for (auto [duration, deadline] : tasks) {
        time += duration;
        ans += deadline - time;
    }

    cout << ans;
}