#include<iostream>
using namespace std;
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        long long a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n-1;i++){
            if(a[i]<2LL * a[i+1]){
                b[i]=1;
            }
            else{
                b[i]=0;
            }
        }
        int count =0;
        for(int i=0;i<k;i++){
            count = count + b[i];
        }
        int ans;
        if(count==k){
            ans =1;
        }
        else{
            ans =0;
        }
        for(int i=k;i<n-1;i++){
            count = count + b[i]-b[i-k];
            if(count==k){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}