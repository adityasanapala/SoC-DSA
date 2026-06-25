#include <bits/stdc++.h>
using namespace std;

long long d(long long n) {
    if(n < 10) return n;
    long long sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return d(sum);
}

 int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, count = 0;
    cin >> n;

    for(long long i = 1; i <= n; i++) {
        for(long long j = 1; j <= n; j++) {
            for(long long k = 1; k <= n; k++) {
                if(d(k)== d(d(i)*d(j)) && k != i*j) {
                count ++;
                }     
                }
            }
   }
    cout << count << "\n";
    return 0;
}