#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
long long x,n,cost=0;
cin >> x>>n;
priority_queue<long long, vector<long long>, greater<long long>> pq;
for(int i=0;i<n;i++){
    long long stick;
    cin >> stick;
    pq.push(stick);
}
while(pq.size()>1){
    long long a = pq.top();
    pq.pop();
    long long b = pq.top();
    pq.pop();
    long long newstick = a+b;
    pq.push(newstick);
    cost = cost+newstick;
}
cout<<cost;
return 0;
}