#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<long long> v;
    long long n;
    cin>>n;
    for(long long i = 0; i < n; i++){
        long long x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    long long m = (long long)v.size();
    long long mid = m/2;
    long long ans = 0;
    for(long long i = 0; i < m; i++){
        ans += abs(v[mid] - v[i]);
    }
    cout<<ans<<endl;
    return 0;
}