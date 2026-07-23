#include <bits/stdc++.h>
using namespace std;
 
int main (){
    
    string s; cin >> s;
    stack<int> st;
    st.push(-1);
    int maxLen = 0 ; int count = 1;
    
    for (int i =0 ; i < s.size() ; i++){
        
    if(s[i] == '('){
        st.push(i);
    }
    else {
        st.pop();
        if (st.empty()) {
            st.push(i);
        }
        else {
            int len = i - st.top();
            if(len > maxLen) {
                maxLen = len;
                count = 1;
            }
            
            else if (len == maxLen) {
                count++;
            }
        }
    }
    }
    if (maxLen == 0)
    cout << "0 1" << endl;
    else 
    cout << maxLen << " " << count << endl;
    return 0;
}