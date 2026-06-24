#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, x;
    cin>>n>>x;
    vector<long long> v;
    vector<pair<long,long>> p;
    for(long long i = 0; i < n; i++){
        long long p;
        cin>>p;
        v.push_back(p);
    }
    for(long long i = 0; i < n; i++){
        p.push_back({v[i],i});
    }
    sort(p.begin(), p.end());
    sort(v.begin(), v.end());
    for(long long i = 0; i < n; i++){
        long long target = x - v[i];
        long long left = i+1;
        long long right = n-1;
        while(left < right){
            if(v[left] + v[right] == target){
                cout<<p[i].second+1<<" "<<p[left].second + 1<<" "<<p[right].second + 1<<endl;
                return 0;
            }
            if(v[left] + v[right] > target){
                right--;
                continue;
            }
            if(v[left] + v[right] < target){
                left++;
                continue;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}