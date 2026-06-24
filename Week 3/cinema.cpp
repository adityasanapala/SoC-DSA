#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void seating(int m, int k, bool** &filled){
    int x = k / 2;
    int yl = (k - m) / 2;
    int yr = yl + m - 1;
    for(int i = 0; i < (k - 1)/2; i++){
        //check row k / 2 - i
        for(int j = yl; j <= yr; j++){
            if (filled[k / 2 - i][j]){
                break;
            }
        }

        //check row k / 2 + i
        for(int j = yl; j <= yr; j++){
            if(filled[k / 2 + i][j]){
                break;
            }
        }
        
    }
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

    int n, k;
    int req[n];
    bool filled[k][k] = {false};

    cin >> n >> k;
    int xc = (k / 2) + 1, yc = (k / 2) + 1;

    for(int i = 0; i < n; i++){
        cin >> req[i];
    }

    

    return 0;
}