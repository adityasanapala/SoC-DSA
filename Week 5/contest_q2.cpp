#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int count1[n+1],count2[n+1],count3[n+1],val[n+1];
        count1[0] = 0;
        count2[0] = 0;
        count3[0] = 0;
        val[0] = 0;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            count1[i] = count1[i-1];
            count2[i] = count2[i-1];
            count3[i] = count3[i-1];
            if(x==1){
                count1[i]++;
            }
            else if(x==2){
                count2[i]++;
            }
            else{
                count3[i]++;
            }
            val[i]=count1[i]+count2[i]-count3[i];
        }
        int best = 1e9;
        bool y=false;
        for(int i=2;i<n;i++){
            int j=i-1;
            if(count1[j]>=count2[j]+count3[j]){
                best = min(best, val[j]);
            }
            if (best <= val[i]) {
                y = true;
                break;
            }
        }
        if(y==true){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}