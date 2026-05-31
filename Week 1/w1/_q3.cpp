#include<bits/stdc++.h>
using namespace std;
bool coin(long long n, long long k){
        if(n%2==0){
            return true;
        }
        else if(k%2!=0&&(n-k>=0)){
            return true;
        }
    return false;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
long long n,k;
int p;
cin >> p;
for(int i=0;i<p;i++){
    cin >> n >> k;
    if(coin(n,k)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}
}