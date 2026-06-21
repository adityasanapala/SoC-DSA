#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ll n,k,m,sum,a,b,min=1000001;
    cin>>n>>k;
    bool array[k][k];
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            array[i][j]=0;
        } 
    }
    for(int i=0;i<n;i++){
        min=1000001;
        cin>>m;
        a=k;
        b=k;
        for(int x=0;x<k;x++){
            for(int y=0;y<=k-m;y++){
                sum=0;
                for(int i=0;i<m;i++){
                    if(array[x][y+i]==0)sum+=abs(x-k/2)+abs(y+i-k/2);
                    else {
                        sum=1000002;
                        break;
                    }
                }
                if(sum<min){
                    a=x;
                    b=y;
                    min=sum;
                }
            }
        }
        if(a==k&&b==k)cout<<-1<<'\n';
        else{
            cout<<a+1<<" "<<b+1<<" "<<b+m<<'\n';
            for(int i=0;i<m;i++){
                array[a][b+i]=1;
            }
        }
    }
}