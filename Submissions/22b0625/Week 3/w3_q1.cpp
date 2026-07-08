
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<long long, long long>> tasks(n);

    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end());

    long long time = 0;
    long long reward = 0;

    for (auto task : tasks) {
    long long duration = task.first;
    long long deadline = task.second;

    time += duration;
    reward += deadline - time;
}

    cout << reward << '\n';

    return 0;
}