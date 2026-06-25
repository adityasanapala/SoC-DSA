#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long d[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
        }
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                long long p = d[x][a]+1LL*c+d[b][y];
                long long q = d[x][b]+1LL*c+d[a][y];
                long long r= min(p,q);
                d[x][y]=min(d[x][y],r);
            }
        }
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += d[i][j];
            }
        }
        cout << ans << ' ';
    }
    cout<<endl;
    return 0;
}