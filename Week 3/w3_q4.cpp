#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;

long long solve(string &x, string &y, long long n, long long m){
    if(n == 0) return m;
    if(m == 0) return n;
    if(dp[n][m] != -1) return dp[n][m];
    if(x[n-1] == y[m-1]) return dp[n][m] = solve(x,y,n-1,m-1);
    else return dp[n][m] = 1 + min(solve(x,y,n-1,m-1), min(solve(x,y,n-1,m), solve(x,y,n,m-1)));
}

int main(){
    string s1;
    string s2;
    cin>>s1>>s2;
    dp.resize(s1.size()+1, vector<long long>(s2.size()+1, -1));
    long long ans = solve(s1,s2,s1.size(),s2.size());
    cout<<ans<<endl;
    return 0;
}