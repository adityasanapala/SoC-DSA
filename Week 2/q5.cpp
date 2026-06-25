#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    long long cost = 0;
    sort(p,p+n);
    for(int i=0;i<n/2;i++){
        cost = cost + p[n-1-i]-p[i];
    }
    cout<<cost<<"\n";
}