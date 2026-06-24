#include<bits/stdc++.h>
using namespace std;

int main(){
    long long x, n;
    cin>>x>>n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(long long i = 0; i < n; i++){
        long long a;
        cin>>a;
        pq.push(a);
    }
    long long cost = 0;
    while(pq.size() > 1){
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        long long sum = a+b;
        cost += sum;
        pq.push(sum);
    }
    cout<<cost<<endl;
    return 0;
}