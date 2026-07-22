#include<iostream>
#include<string>
using namespace std;
int main(){
    int n=0,l=0;
    string s;
    while(getline(cin,s)){
        if(s.size()==0) break;
        if(s[0]=='+')n++;
        else if(s[0]=='-')n--;
        else{
            int k=0;
            while(s[k]!=':') k++;
            l=l+n*(s.size()-k-1);
        }
    }
    cout<<l<<'\n';
}

