#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    stack<int> st;
    st.push(-1);
    int mx = 0;
    int cnt = 1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            st.pop();
            if(st.empty()){
                st.push(i);
            }
            else{
                int len = i - st.top();
                if(len > mx){
                    mx = len;
                    cnt = 1;
                }
                else if (len == mx){
                    cnt++;
                }
            }
        }
    }
    cout<<mx<<" "<<cnt<<endl;
    return 0;
}