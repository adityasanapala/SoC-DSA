#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 400005;

long long fact[MAX];
long long invfact[MAX];

long long power(long long base, long long exp){
    long long res = 1;
    base %= MOD;
    while(exp > 0){
        if(exp%2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modinverse(long long n){
    return power(n, MOD - 2);
}

void precompute(){
    fact[0] = 1;
    invfact[0] = 1;
    for(int i = 1; i < MAX; i++){
        fact[i] = (fact[i-1] * i)%MOD;
    }
    invfact[MAX-1] = modinverse(fact[MAX-1]);
    for(int i = MAX - 2; i >= 1; i--){
        invfact[i] = (invfact[i+1] * (i+1))%MOD;
    }
}

long long ncr(int n, int r){
    if(r < 0 || r > n) return 0;
    return fact[n] * invfact[r]%MOD * invfact[n-r]%MOD;
}

int main(){
    precompute();
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i = 0; i <= n; i++){
        cin>>a[i];
    }
    long long ans = 0;
    for(int x = 0; x <= n; x++){
        if(a[x] == 0) continue;
        ans = (ans + ncr(x + a[x], x+1))%MOD;
    }
    cout<<ans<<endl;
    return 0;
}