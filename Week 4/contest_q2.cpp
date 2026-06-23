#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n/2-1;i++){
        cout<<s[2*i]<<s[2*i+1]<<"-";
    }
    if(n%2==0){
        cout<<s[n-2]<<s[n-1];
    }
    else{
        cout<<s[n-3]<<s[n-2]<<s[n-1];
    }
    cout<<endl;
}