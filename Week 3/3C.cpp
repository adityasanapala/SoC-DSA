#include<bits/stdc++.h>
using namespace std;

int dr(long long x){
    while(x > 9){
        long long sum = 0;
        while(x){
            sum += x%10;
            x /= 10;
        }
        x = sum;
    }
    return x;
}

int main(){
    int n;
    cin>>n;
    vector<long long> cnt(10);
    for(long long i = 1; i <= n; i++){
        cnt[dr(i)]++;
    }
    long long ans = 0;
    for(int a = 1; a <= 9; a++){
        for(int b = 1; b <= 9; b++){
            int c = dr(a*b);
            ans += cnt[a]*cnt[b]*cnt[c];
        }
    }
    for(long long a = 1; a <= n; a++){
        for(long long b = 1; a*b <= n; b++){
            ans--;
        }
    }
    cout<<ans<<endl;
    return 0;
}