#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        long long c[k];
        int count2=0,count3=0;
        for(int i=0;i<k;i++){
            cin>>c[i];
            if(c[i]==2){
                count2++;
            }
            else if(c[i]>=3){
                count3++;
            }
        }
        if(count2 >=2 || count3>=1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}