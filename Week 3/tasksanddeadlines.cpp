#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long time=0,reward=0;
    cin >> n; 
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks.begin(),tasks.end());
    for(int i=0;i<n;i++){
        time+=tasks[i].first;
        reward+=(tasks[i].second - time);
    }
    cout << reward << "\n";
    return 0;
}