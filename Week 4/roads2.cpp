#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;

struct Road{
    int c1;
    int c2;
    Road() = default;
    Road(int a, int b){
        c1 = a;
        c2 = b;
    }
};

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

    ll n;
    cin >> n;

    vector<Road> roads(n - 1);

    for(ll i = 0; i < n - 1; i++){
        cin >> roads[i].c1 >> roads[i].c2;
    }

    ll days = 0;


    return 0;
}
