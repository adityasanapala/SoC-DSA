#include <iostream>
#include <algorithm>

using namespace std;

struct Task {
    int dur;
    int dead;
};

bool comp(const Task& a, const Task& b) {
    return a.dur < b.dur;
}

int main() {
    int n;
    cin >> n;

    Task* tasks = new Task[n];

    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].dur >> tasks[i].dead;
    }

    sort(tasks, tasks + n, comp);

    long long cur = 0;
    long long reward = 0;
 
    for (int i = 0; i < n; ++i) {
        cur += tasks[i].dur;
        reward += (tasks[i].dead - cur);
    }

    cout << reward << "\n";

    delete[] tasks;

    return 0;
}