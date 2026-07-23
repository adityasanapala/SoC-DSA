#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
stack<int> s;
string t;
cin >> t;
s.push(-1);
int len=0,max_len=0,n=1;
for(int i=0;i<t.length();i++){
    if(t[i]=='('){
        s.push(i);
    }
    else if (t[i]==')'){
        s.pop();
        if(s.empty()){
            s.push(i);
            
        }
        else{
            len= i-s.top();
            if(len>max_len){
                max_len = len;
                n=1;
            }
            else if(len==max_len){
                n++;
            }
        }
    }
}
cout << max_len << " " << n << endl;
}