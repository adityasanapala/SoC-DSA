#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int cnt=1;
    int pcnt=0;
    for (int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){cnt++;}
        else{
        if (cnt>pcnt)
        {pcnt=cnt;
        cnt=1;}
        else{cnt=1;}
        }
    }
     if (cnt>pcnt)
        {pcnt=cnt;
        cnt=1;} 
    cout<<pcnt;
    
    return 0;
}