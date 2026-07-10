#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //for faster IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);
    int n = s.length();
    // while (cin >> x){
    //     //code
    // }

    vector<int> dp(n, 0);
    stack<int> st;
    int longest = 0, count = 0;
    for(int i = 0; i < n; i++){
        char c = s[i];
        if(s[i] == '('){
            st.push(i);
            continue;
        }
        if(st.empty()) continue;
        int j = st.top();
        st.pop();
        dp[i] = i - j + 1 + (j >= 1 ? dp[j - 1] : 0);
        if(dp[i] > longest){
            longest = dp[i];
            count = 1;
        }
        else if(dp[i] == longest){
            count++;
        }
    }
    if(longest == 0) cout << "0 1\n";
    else cout << longest <<" " <<count <<endl;
    return 0;
}
