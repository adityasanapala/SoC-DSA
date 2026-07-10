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
    
    while(t--){
        int k;
        cin >> k;
        
        vector<int> c(k);
        for(int i = 0; i < k; i++){
            cin >> c[i];
        }

        sort(c.begin(), c.end(), greater<int>());
        if(c[0] >= 3){
            cout << "Yes\n";
        }
        else if(c[0] == 2 && c[1] == 2){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    
    return 0;
}
