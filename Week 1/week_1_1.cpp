#include<iostream>

using namespace std;

int main() {
    long long n;
    long long a;
    cin >> n;
    long long sum=0;
    for (long long i=0; i<n-1; i++) {
        cin>>a;
        sum +=a;

    }
    long long A= (n*(n+1))/2;
    long long ans= A- sum;
    cout << ans<<endl;
    return 0;
}