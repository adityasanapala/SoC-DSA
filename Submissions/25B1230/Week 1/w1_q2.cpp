#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    int o=1,ans=1;

    for(int i=1; i<s.size(); i++){

        if(s[i]==s[i-1]){
           o=o+1;
        }
        else{
            o=1;
        }
         ans=max(ans,o);
    }
    cout << ans;
}