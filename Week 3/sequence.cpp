#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
long long n,cost=0;
cin >> n;
priority_queue<long long> pq;

for(int i=0;i<n;i++){
    long long x;
    cin >> x;
    pq.push(x);

    if(pq.top()>x){
        cost += (pq.top()-x);
        pq.pop();
        pq.push(x);
    }
}
cout << cost;
return 0;
}