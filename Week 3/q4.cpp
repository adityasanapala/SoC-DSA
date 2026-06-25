#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int m= b.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0){
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=i;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                int x=min(dp[i][j - 1], dp[i - 1][j]);
                dp[i][j] = 1 + min(x,dp[i-1][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<"\n";
}