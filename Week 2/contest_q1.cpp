#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    long long ans=0;
    int count =0;
    while(getline(cin,s)){
        if(s[0]=='+')
            count++;
        else if(s[0]=='-')
            count--;
        else{
            int pos = s.find(':');
            int len = s.size() - pos - 1;
            ans += 1LL * len * count;
        }
    }
    cout<<ans<<"\n";
    return 0;
}