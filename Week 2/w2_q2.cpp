#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, x;
    cin>>n>>x;
    vector<long long> v;
    for(long long i = 0; i < n; i++){
        long long p;
        cin>>p;
        v.push_back(p);
    }
    map<long long, long long> m;
    for(long long i = 0; i < n; i++){
        long long diff = (x - v[i]);
        if(m.find(diff) != m.end()){
            cout<< m[diff] + 1 << " " << i + 1 << endl;
            return 0;
        }
        m[v[i]] = i;
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}