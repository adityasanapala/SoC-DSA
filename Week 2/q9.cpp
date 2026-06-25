#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long x[n],y[n];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    int a[n],b[n];
    for(int i=0;i<n;i++){
        a[i]=0;
        b[i]=0;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(x[i]<=x[j] && y[i]>=y[j]){
                a[i]++;
            }
            else if(x[i]>=x[j] && y[i]<=y[j]){
                b[i]++;
            }
        }
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}