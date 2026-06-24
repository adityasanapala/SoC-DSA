#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, t;
    cin>>n>>t;
    vector<long long> v(n);
    for(long long i = 0; i < n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    if(v.empty()) return 0;
    long long low = 1;
    long long high = v[0]*t;
    long long ans = 0;
    long long y = 0;
    while(low <= high){
        y = 0;
        long long mid = (low + (high-low)/2);
        for(int i = 0; i < n; i++){
            y += mid/v[i];
            if(y >= t) break;
        }
        if(y >= t){
            ans = mid;
            high = mid - 1;
            continue;
        }
        if(y < t){
            low = mid + 1;
            continue;
        }
    }
    cout<<ans<<endl;
    return 0;
}