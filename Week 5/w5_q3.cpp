#include<bits/stdc++.h>
using namespace std;

using int64 = long long;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        int carry = 0;
        bool ok = true;
        for(int i = n-1; i >= 1; i--){
            bool possible = false;
            for(int a = 5; a <= 9 && !possible; a++){
                for(int b = 5; b <= 9 && !possible; b++){
                    int sum = a+b+carry;
                    if(sum%10 == s[i] - '0'){
                        possible = true;
                        carry = sum/10;
                    }
                }
            }
            if(!possible){
                ok = false;
                break;
            }
        }
        if((ok) && (carry == 1) && (s[0] == '1')) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}