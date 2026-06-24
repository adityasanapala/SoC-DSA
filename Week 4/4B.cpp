#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<char> digits(n);
    for(long long i = 0; i < n; i++){
        cin>>digits[i];
    }
    string ans;
    long long m = digits.size();
    if(m%2 == 0){
        for(long long i = 0; i < n; i++){
            if(i!= 0 && i%2 == 0){
                ans += '-';
            }
            ans += digits[i];
        }
        cout<<ans<<endl;
        return 0;
    }
    else{
        for(long long i = 0; i < n; i++){
            ans += digits[i];
            if(i != 0 && i != n-1 && i%2 == 0){
                ans += '-';
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    return 0;
}