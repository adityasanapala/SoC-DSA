#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    int mx = 0;
    for(int i = 0; i < n; i++){
        cin>>h[i];
        if(h[i] > h[mx]) mx = i;
    }
    vector<int>a;
    for(int i = 0; i < n; i++){
        a.push_back(h[(mx+i)%n]);
    }
    long long ans = 0;
    stack<pair<int, int>> st;
    st.push({a[0], 1});
    for(int i = 1; i < n; i++){
        int curr = a[i];
        while(!st.empty() && st.top().first < curr){
            ans += st.top().second;
            st.pop();
        }
        if(st.top().first == curr){
            int cnt = st.top().second;
            st.pop();
            ans += cnt;
            if(!st.empty()) ans++;
            st.push({curr, cnt+1});
        }
        else{
            ans++;
            st.push({curr,1});
        }
    }
    while(st.size() > 2){
        ans += st.top().second;
        st.pop();
    }
    if(st.size() == 2){
        auto p = st.top();
        st.pop();
        if(st.top().second >= 2){
            ans += p.second;
        }
    }
    cout<<ans<<endl;
    return 0;
}