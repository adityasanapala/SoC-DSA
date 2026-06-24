#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    set<long long> s;
    queue<long long> q;
    long long ans = 0;
    for(long long i = 0; i < n; i++){
        long long x;
        cin>>x;
        if(s.count(x) == 0){
            s.insert(x);
            q.push(x);
            ans = max(ans, (long long)q.size());
            continue;
        }
        if(s.count(x) == 1){
            while(q.front() != x){
                s.erase(q.front());
                q.pop();
            }
            s.erase(q.front());
            s.insert(x);
            q.pop();
            q.push(x);
            ans = max(ans, (long long)q.size());
            continue;
        }
    }
    cout<<ans<<endl;
    return 0;
}