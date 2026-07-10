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

    int n;
    cin >> n;
    string num;
    cin >> num;

    if(n % 2 == 0){
        for(int i = 0; i < n; i+=2){
            cout <<num[i] <<num[i + 1];
            if(i != n - 2){
                cout << "-";
            }
        }
    }
    else{
        for(int i = 0; i < n - 2; i+= 2){
            if(i != n - 3){
                cout <<num[i] <<num[i + 1] <<"-";
            }
            else{
                cout << num[i] <<num[i + 1] <<num[i + 2];
            }
        }
    }
    cout << endl;

    return 0;
}
