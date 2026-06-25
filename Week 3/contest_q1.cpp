#include<iostream>
using namespace std;
int main(){
    int n,p1,p2,p3,t1,t2;
    cin>>n>>p1>>p2>>p3>>t1>>t2;
    int l[n],r[n];
    long power=0;
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i];
        power = power + p1*(r[i]-l[i]);
    }
    for(int i=0;i<n-1;i++){
        if(l[i+1]-r[i]<=t1){
            power = power + p1*(l[i+1]-r[i]);
        }
        else if(l[i+1]-r[i]<= t1+t2){
            power = power + p1*t1 + p2*(l[i+1]-r[i]-t1);
        }
        else{
            power = power + p1*t1 + p2*t2 + p3*(l[i+1]-r[i]- t1-t2);
        }
    }
    cout<<power<<endl;
    return 0;
}