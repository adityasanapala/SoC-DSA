#include <iostream>
#include <vector>
using namespace std;

int main(){
       long long n;
       cin>>n;
       vector<int> v(n);
       for(int i=0;i<n;i++){
        cin>>v[i];
       }
       int even=0,odd=0;
       for(int i=0;i<n;i++){

        if(v[i]%2==0){even++;}
        else odd++;
       }
       if(even==1){
        for(int i=0;i<n;i++){
            if(v[i]%2==0)cout<<i+1<<endl;
       }
    }
    else {
        for(int i=0;i<n;i++){ 
        if(v[i]%2!=0){
            cout<<i+1<<endl;
        }
    }}
}
