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

    int n;
    cin >> n;
    ll x;
    cin >> x;

    vector<pair<ll, int>> nums(n);

    for(int i =  0; i < n; i++){
        cin >> nums[i].first;
        nums[i].second = i + 1;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = n - 1;

        while (l < r) {
            ll sum = nums[i].first + nums[l].first + nums[r].first;

            if (sum == x) {
                cout << nums[i].second << " "<< nums[l].second << " "<< nums[r].second << endl;
                return 0;
            }

            if (sum < x)
                l++;
            else
                r--;
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}