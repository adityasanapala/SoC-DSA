#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    int n,p1,p2,p3,t1,t2;
    ll power=0;
    cin>>n>>p1>>p2>>p3>>t1>>t2;
    int r[n],l[n];
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i];
        power+=(r[i]-l[i])*p1;
    }
    if(n>1){
        for(int i=1;i<n;i++){
            int t=l[i]-r[i-1];
            if(t>(t1+t2)){
                power+=(t-t1-t2)*p3+t2*p2+t1*p1;
            }
            else if(t>t1){
                power+=(t-t1)*p2+t1*p1;
            }
            else{
                power+=t*p1;
            }
        }
    }
    
    cout<<power<<'\n';
} 