#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<long long>> d(n, vector<long long>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>d[i][j];
        }
    }
    int k;
    cin>>k;
    while(k--){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                d[i][j] = min({d[i][j], d[i][a]+c+d[b][j], d[i][b]+c+d[a][j]});
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                ans += d[i][j];
            }
        }
        cout<<ans<<" ";
    }
    return 0;
}