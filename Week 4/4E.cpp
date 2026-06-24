#include<bits/stdc++.h>
using namespace std;

int overlap(string a, string b){
    if(a.empty() || b.empty()) return 0;
    string s = b + '#' + a;
    int n = s.size();
    vector<int> pi(n,0);
    bool contained = false;
    for(int i = 1; i < n; i++){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
        if(j == b.size()) contained = true;
    }
    if(contained) return b.size();
    return pi.back();
}

int mergelength(string a, string b, string c){
    int ans = a.size();
    int x = overlap(a,b);
    ans += b.size() - x;
    string temp = a+b.substr(x);
    int y = overlap(temp, c);
    ans += c.size() - y;
    return ans;
}

int main(){
    string s[3];
    for(int i = 0; i < 3; i++){
        cin>>s[i];
    }
    vector<int> p = {0,1,2};
    int ans = INT_MAX;
    do{
        int curr = mergelength(s[p[0]], s[p[1]], s[p[2]]);
        ans = min(ans,curr);
    }while(next_permutation(p.begin(), p.end()));
    cout<<ans<<endl;
    return 0;
}