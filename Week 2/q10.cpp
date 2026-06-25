#include<iostream>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    int row[n],col[n];
    for(int i=0;i<n;i++){
        row[i]=0;
        col[i]=0;
    }
    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t==1){
            int x,y;
            cin>>x>>y;
            row[y-1]=row[y-1]+1;
            col[x-1]=col[x-1]+1;
        }
        else if(t==2){
            int x,y;
            cin>>x>>y;
            row[y-1]=row[y-1]-1;
            col[x-1]=col[x-1]-1;
        }
        else if(t==3){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            int countx=0,county=0;
            for(int x=x1;x<=x2;x++){
                if(col[x-1]>0){
                    countx++;
                }
            }
            for(int y=y1;y<=y2;y++){
                if(row[y-1]>0){
                    county++;
                }
            }
            if((countx == x2-x1+1) || (county == y2 -y1 +1)){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
        }
    }
}