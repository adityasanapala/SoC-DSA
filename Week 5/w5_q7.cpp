#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int R,G,B;
    cin>>R>>G>>B;

    vector<int> red(R);
    vector<int> green(G);
    vector<int> blue(B);

    for(int i=0;i<R;i++){
        cin>>red[i];
    }

    for(int i=0;i<G;i++){
        cin>>green[i];
    }

    for(int i=0;i<B;i++){
        cin>>blue[i];
    }

    sort(red.begin(),red.end(),greater<int>());
    sort(green.begin(),green.end(),greater<int>());
    sort(blue.begin(),blue.end(),greater<int>());

    vector<vector<vector<ll>>> dp(
        R+1,
        vector<vector<ll>>(G+1,vector<ll>(B+1,0))
    );

    ll answer=0;

    for(int i=0;i<=R;i++){
        for(int j=0;j<=G;j++){
            for(int k=0;k<=B;k++){

                answer=max(answer,dp[i][j][k]);

                if(i<R && j<G){
                    dp[i+1][j+1][k]=max(dp[i+1][j+1][k],
                    dp[i][j][k]+1LL*red[i]*green[j]);
                }

                if(i<R && k<B){
                    dp[i+1][j][k+1]=max(dp[i+1][j][k+1],
                    dp[i][j][k]+1LL*red[i]*blue[k]);
                }

                if(j<G && k<B){
                    dp[i][j+1][k+1]=max(dp[i][j+1][k+1],
                    dp[i][j][k]+1LL*green[j]*blue[k]);
                }
            }
        }
    }

    cout<<answer<<endl;

    return 0;
}