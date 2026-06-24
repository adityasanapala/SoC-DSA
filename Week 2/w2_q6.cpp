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
    
    int t;
    cin >> t;

    for(int j = 0; j < t; j++){
        int n;
        cin >> n;
        int a[n];
        int pos[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            pos[a[i]] = i;
        }
    
        int len[n + 1];
        len[n] = 1;
        int ans = n;
        
        for(int i = n - 1; i >= 1; i--){
            if(pos[i] < pos[i + 1]){
                len[i] = len[i + 1] + 1;
            }
            else{
                len[i] = 1;
            }
        }
    
        for(int i = 1; i <= n; i++){
            ans = min(ans, max(i - 1, n - (i + len[i] - 1)));
        }
    
        cout << ans << endl;
    }
    
    return 0;
}