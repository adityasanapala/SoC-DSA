#include<iostream>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    long long int arr[n];
    long long int ssum =0;
    long long int sum ;
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
        ssum = arr[i]+ssum;
    }
    sum = n*(n+1);
    sum = sum/2;
    // return 

    
    cout<<sum -ssum;
    return 0;
}