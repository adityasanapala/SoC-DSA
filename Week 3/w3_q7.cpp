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

    ll x, n;
    cin >>x >>n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        pq.push(a);
    }

    ll ans = 0;

    for(int i = 1; i < n; i++){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b);
        ans += a + b;
    }

    cout <<ans <<endl;

    return 0;
}