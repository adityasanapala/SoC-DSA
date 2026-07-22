#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ll t,n,k,num;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        ll a[n];
        ll sum=0,num=0;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        bool m[n-1];
        for(int j=0;j<n-1;j++){
            if(a[j]<2*a[j+1])m[j]=1;
            else m[j]=0;
        }
        for(int j=0;j<k;j++){
            sum+=m[j];
        }
        if(sum==k)num++;
        for(int j=k;j<n-1;j++){
            sum += m[j] - m[j-k];
            if(sum == k) num++;
        }
        cout<<num<<endl;
    }
}
//done