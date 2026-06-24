#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //for faster IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //string s;
    //getline(cin, s);
    // while (cin >> x){
    //     //code
    // }

    int n, p1, p2, p3, T1, T2;
    cin >> n >>p1 >>p2 >>p3 >>T1 >>T2;
    vector<pair<int, int>> work(n);
    for(int i = 0; i < n; i++){
        cin >> work[i].first >>work[i].second;
    }

    int power = 0;
    for(int i = 0; i < n; i++){
        power += p1 * (work[i].second - work[i].first);
    }
    for(int i = 1; i < n; i++){
        int t1 = min((work[i].first - work[i - 1].second), T1);
        power += p1 * t1;
        int t2 = min((work[i].first - work[i - 1].second - t1), T2);
        power += p2 * t2;
        int t3 = work[i].first - work[i - 1].second - t1 - t2;
        power += p3 * t3;
    }

    cout << power <<endl;

    return 0;
}