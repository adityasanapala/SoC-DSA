//Stick lengths |x-a1|+|x-a2|+...|x-an| min value

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll=long long;

int main(){
    ll n,len,sum=0;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    //n is odd median is req len
    // n is odd any value in b/w n/2 to n/2-1 works
    if(n%2==0){
        len=v[n/2];
    }
    else len=v[(n-1)/2];
    for(int i=0;i<n;i++){
        sum+=abs(len-v[i]);
    }
    cout<<sum;
}