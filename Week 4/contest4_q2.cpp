#include <iostream>
#include <vector>
using namespace std;

int main(){
        int n=0;
       string v;
       cin>>n>>v;
       if(n%2==0){
        int i=0;
        int k=n;
        if(n!=2){
        do{
            cout<<v[i]<<v[i+1]<<"-";
            k=k-2;
            i+=2;
        }while(k>2);}
        
        cout<<v[n-2]<<v[n-1]<<endl;
       }
       if(n%2==1){
        int i=0;
        int k=n;
        if(n!=3){
        do{
            cout<<v[i]<<v[i+1]<<"-";
            i+=2;
            k-=2;
        }while(k>3);}
        cout<<v[n-3]<<v[n-2]<<v[n-1]<<endl;
       }
    
}