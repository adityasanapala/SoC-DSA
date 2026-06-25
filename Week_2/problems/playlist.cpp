#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    long long n,t=0;
    cin >> n;
    map<long long, long long> a;
    long long counter = 0;
    long long ans = 0;
    for(long long i=0;i<n;i++){
        long long p;
        cin >> p;
        if(a.find(p) != a.end() && a.find(p)->second >= t){
            t = a.find(p)->second+1;
            counter = i-t+1;

        }
        else{
            counter++;
        }
        ans=max(counter,ans);
        a[p]=i;
    }
    cout << ans << "\n";
    return 0;
}