#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //for faster IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    vector<string> lines;

    ll longest = 0;
    //getline(cin, s);
    while (getline(cin, s)){
        longest = max(longest, (ll)s.size());
        lines.push_back(s);
    }
    longest += 2;
    int left_closer = 1;
    int len = lines.size();
    for(ll i = 0; i < len + 2; i++){
        
        if(i == 0 || i == len + 1){
            for(ll j = 0; j < longest; j++){
                cout << "*";
            }
        } 
        else {
            ll left;
            if((longest - lines[i - 1].size()) % 2 == 0 ){
                left = (longest - 2 - lines[i - 1].size()) / 2; //left closer
                for(ll j = 0; j < longest; j++){
                    if(j == 0 || j == longest - 1){
                        cout << "*";
                    }else if(j <= left || j > left + lines[i - 1].size()){
                        cout << " ";
                    } else {
                        cout << lines[i - 1][j - left - 1];
                    }
                }
            }
            else{
                if(left_closer == 1){
                    left = (longest - 2 - lines[i - 1].size()) / 2; //left closer
                    for(ll j = 0; j < longest; j++){
                        if(j == 0 || j == longest - 1){
                            cout << "*";
                        }else if(j <= left || j > left + lines[i - 1].size()){
                            cout << " ";
                        } else {
                            cout << lines[i - 1][j - left - 1];
                        }
                        
                    }
                    left_closer *= -1;
                }
                else {
                    left = (longest - lines[i - 1].size()) / 2; //right closer
                    for(ll j = 0; j < longest; j++){
                        if(j == 0 || j == longest - 1){
                            cout << "*";
                        }else if(j <= left || j > left + lines[i - 1].size()){
                            cout << " ";
                        } else {
                            cout << lines[i - 1][j - left - 1];
                        }

                    }

                    left_closer *= -1;
                }

            }
            
            
        }
        cout << endl;
    }
        
}

