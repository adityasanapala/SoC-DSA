#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;    
    if(n % 2 == 0){
        int i = 0;
        while(i < n){
            cout << str[i] << str[i+1];
            if(i + 2 < n){
                cout << "-";
            }
            i += 2;
        }
    }
    else{
        if(n == 3){
            cout << str[0] << str[1] << str[2];
        }
        else{
            int middle_group_start = (n - 3) / 2;
            if(middle_group_start % 2 != 0){
                middle_group_start--;
            }  
            int i = 0;
            while(i < n){
                if(i == middle_group_start){
                    cout << str[i] << str[i+1] << str[i+2];
                    if(i + 3 < n){
                        cout << "-";
                    }
                    i += 3;
                }
                else{
                    cout << str[i] << str[i+1];
                    if(i + 2 < n){
                        cout << "-";
                    }
                    i += 2;
                }
            }
        }
    }
    
    return 0;
}