#include<iostream>
using namespace std;

int main() {
    long double n;
    cin >> n;
    
    long double sum;
    sum = (n*n + n)/2.0000;
    long double sum_get = 0;

    for(int i=0; i<n-1; i++){
        int x;
        cin >> x;
        sum_get = sum_get + x;
    }
    cout << sum - sum_get;
}