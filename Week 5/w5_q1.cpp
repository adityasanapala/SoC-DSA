#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int>>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define input(v,n) for(int i=0;i<n;i++) cin>>v[i]
#define pb(a) push_back(a)
#define all(a) (a).begin(),(a).end()

void solve() {
    string s;
    cin >> s;
    stack<int> st;
    st.push(-1);
    int len_max = 0;
    int num = 1;
    for (int i = 0; i < s.length();i++){
        if(s[i]=='(')
            st.push(i);
        else{
            st.pop();
            if(!st.empty()){
                int curr_len = i - st.top();
                if(curr_len>len_max){
                    len_max = curr_len;
                    num = 1;
                }
                else if(curr_len==len_max&&len_max>0){
                    num++;
                }
            }
            else st.push(i);
        }
    }
    cout << len_max << " " << num << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}