#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int d[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
        }
    }
    int k,a,b,c;
    cin>>k;
    for(int p=0;p<k;p++){
        cin>>a>>b>>c;
        a--;
        b--;
        long long q=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=min(d[i][a]+c+d[b][j],d[a][j]+d[i][b]+c);
                d[i][j]=min(x,d[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                q+=d[i][j];
            }
        }
        cout<<q/2<<" ";
    }
}