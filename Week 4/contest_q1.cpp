#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,odd=0,even=0;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
        int y;
        cin>>y;
        a.push_back(y);
    }
    for(int i=0;i<3;i++){
        if(a[i]%2==0)even++;
        else odd++;
    }
    if(even>odd){
        for(int i=0;i<n;i++){
            if(a[i]%2==1)cout<<i+1<<endl;
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(a[i]%2==0)cout<<i+1<<endl;
        }
    }
}