#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int c[500]={};
    int d[500];
    for(int i=0;i<500;i++){
        d[i]=-1;
    }
    for(int i=0;i<n;i++){
        int currentBest=0;
        int currentpos=-1;
        for(int j=0;j<m;j++){
            if(a[i]==b[j]){
                if(currentBest+1>c[j]){
                    c[j]=currentBest+1;
                    d[j]=currentpos;
                }
            }
            else if(a[i]>b[j]){
                if(c[j]>currentBest){
                    currentBest=c[j];
                    currentpos=j;
                }
            }
        }
    }
    int len = 0;
    int pos = -1;
    for(int j=0;j<m;j++){
        if(c[j]>len){
            len=c[j];
            pos =j;
        }
    }
    cout << len << '\n';
    int ans[505];
    int x = len - 1;

    while (pos != -1) {
        ans[x--] = b[pos];
        pos = d[pos];
    }

    for (int i = 0; i < len; i++)
        cout << ans[i] << ' ';

    cout << '\n';

    return 0;
}