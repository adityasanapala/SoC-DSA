//PlayList

#include <iostream>
#include <set>
#include <vector> 
#include <algorithm>
using ll=long long;
using namespace std;

int main(){
     ll n,result=1,l=0,r=0;
     cin>>n;
     vector<ll> v(n);
     set<ll> s;
     //unique elements in window
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    //r is end of the window
    s.insert(v[0]);
    while(r<n-1){
        if(!s.count(v[r+1])){
            s.insert(v[r+1]);
            r++;
        }
        else{
            while(s.count(v[r+1])){
                result=max(result,r-l+1);
                s.erase(v[l]);
                l++;
            }
        }
    }
    result=max(result,r-l+1);
    cout<<result;
}