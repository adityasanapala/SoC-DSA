#include <iostream>
#include <vector>
using namespace std;

int main(){
       long long n;
       cin>>n;
       vector<vector<int>> d(n,vector<int>(n));
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
        }
       }
       int roads;
       cin>>roads;
       while(roads--){
        int a,b,c;
        long long result=0;
        cin>>a>>b>>c;
        a--;
        b--;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j]=min(d[i][j],min(d[i][a]+c+d[b][j],d[i][b]+c+d[a][j]));
            }
        }
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            result+=d[i][j];
        }
       }
       cout<<result<<" ";}
}
