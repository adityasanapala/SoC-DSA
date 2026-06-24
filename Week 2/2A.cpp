#include<bits/stdc++.h>
using namespace std;

int main(){
    cin>>noskipws;
    bool a = false;
    bool check = true;
    int users = 0;
    int ans = 0;
    char c;
    while(true){
        if(check == false) break;
        else check = false;
        for(cin>>c; c != 10; cin>>c){
            check = true;
            if(c == '+') {
                users++;
            }
            else if(c == '-'){
                users--;
            }
            else{
                if(c != ':' && a == false) continue;
                if(c == ':'){
                    a = true;
                    continue;
            }
            if(c != ':' && a == true) ans = (ans + (1*users));
        }
    }
    a = false;
}
cout<<ans<<endl;
    return 0;
}