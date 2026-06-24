#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e9 + 7;

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

    int t;
    cin >> t;


    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        ll a[n]; //type 1 tower
        ll b[n]; //type 2 tower
        a[0] = 1;
        b[0] = 1;
        for(int i = 1; i < n; i++){
            a[i] = (2 * a[i - 1] + b[i - 1]) % N;
            b[i] = (4 * b[i - 1] + a[i - 1]) % N;
        }
        cout << (a[n - 1] + b[n - 1]) % N << endl; 
    }

    return 0;
}