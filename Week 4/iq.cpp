#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool mysort(pair<int, int> const &a, pair<int, int> const &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

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

    int n;
    cin >> n;
    int arr[n];
    vector<pair<int, int>> remidx(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        remidx[i].first = arr[i] % 2;
        remidx[i].second = i;
    }
    
    sort(remidx.begin(), remidx.end(), mysort);

    if(remidx[0].first == 0 && remidx[1].first == 1){
        cout << remidx[0].second + 1 << endl;
    }
    else if(remidx[n - 1].first == 1 && remidx[n - 2].first == 0){
        cout << remidx[n - 1].second + 1 <<endl;
    }
    return 0;
}
