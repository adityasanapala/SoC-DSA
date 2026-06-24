#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<pair<long long,long long>> task;
    for(long long i = 0; i < n; i++){
        long long a, d;
        cin>>a>>d;
        task.push_back({a,d});
    }
    sort(task.begin(), task.end());
    long long ans = 0;
    long long y = 0;
    for(auto x : task){
        ans += x.second - x.first - y;
        y += x.first;
    }
    cout<<ans<<endl;
    return 0;
}