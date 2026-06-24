#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
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

    int N, W;
    cin >> N >> W;
    vector<pair<int, int>> wv(N + 1);
    wv[0].first = 0;
    wv[0].second = 0;
    for(int i = 1; i < N + 1; i++){
        cin >> wv[i].first >> wv[i].second;
    }

    //do normal knapsack with wv[].first and then with the ones where wv[].first == W, find the one with sum of wv[].second as max



    return 0;
}
