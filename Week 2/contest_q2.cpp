#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    size_t m=0,parity=0;
    string s;
    vector<string>full;
    while(getline(cin,s)){
        m = max(m,s.size());
        full.push_back(s);
    }
    for(size_t i=0;i<=m+1;i++){
        cout<<"*";
    }
    cout<<endl;
    for(string a: full){
        cout<<"*";
        if(a==""){
           for(size_t i=0;i<m;i++){
                cout<<" ";
            } 
        }
        else if((a.size()-m)%2==0){
            for(size_t i=0;i<(m-a.size())/2;i++){
                cout<<" ";
            }
            cout<<a;
            for(size_t i=0;i<(m-a.size())/2;i++){
                cout<<" ";
            }
        }
        else{
            for(size_t i=0;i<(m-a.size())/2+parity;i++){
                cout<<" ";
            }
            parity=1-parity;
            cout<<a;
            for(size_t i=0;i<(m-a.size())/2+parity;i++){
                cout<<" ";
            }
        }
        cout<<"*"<<'\n';
    }
    for(int i=0;i<=m+1;i++){
        cout<<"*";
    }
    cout<<endl;
}