#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    char c=' ', prevc=' ';
    long long count=0, ans=1;
    while(cin>>c){
        if(c==prevc){
            count++;
            if(count>ans){
                ans=count;
            }
        }
        else{
            count = 1;
        }
        prevc=c;
    }
    cout << ans;
    
}