#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n=0,sum=0;
    cin >> n;
    sum = ((n*(n+1))/2);
    for(int i = 0;i<(n-1);i++){
        long long temp = 0;
        cin >> temp;
        sum = sum - temp;
    }
   cout << sum; 
   
}