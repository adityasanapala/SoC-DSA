#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //for faster IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    double a, v, l, d, w;
    cin >> a >> v;
    cin >> l >> d >> w;

    //string s
    //getline(cin, s);
    // while (cin >> x){
    //     //code
    // }

    // Your code here
    double t;
    if(w < v){
        t = min((w / (2 * a) + d / w), w / a);
        double t1 = (-1 * w + sqrt(w * w + 2* a * (l - d))) / a;
        if(t1 < ((v - w) / a)){
            t += t1;
        }
        else{
            t += (v - w) / a + (l - d - (v * v - w * w) / (2 * a)) / v;
        }
    }
    else{
        t = min(v / (2 * a) + l / v, sqrt(2 * l / a));
    }

    
    cout << fixed << setprecision(5) << t << "\n";

    return 0;
}