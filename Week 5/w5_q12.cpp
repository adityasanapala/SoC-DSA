#include<bits/stdc++.h>
using namespace std;

void solve(){
    int k;
    cin>>k;
    long long total_sum = 0;
    priority_queue<long long> pq;
    for(int i = 0; i < k; i++){
        long long c;
        cin>>c;
        total_sum += c;
        pq.push(c);
    }
    vector<long long> f = {1};
    long long f_sum = 1;
    while(f_sum < total_sum){
        long long next_f = (f.size() == 1) ? 1 : f[f.size() - 1] + f[f.size() - 2];
        f.push_back(next_f);
        f_sum += next_f;
    }
    if(f_sum != total_sum){
        cout<<"NO"<<endl;
        return;
    }
    long long prev_held = 0;
    for(int i = f.size() - 1; i >= 0; i--){
        if(pq.empty()){
            cout<<"NO"<<endl;
            return;
        }
        long long current = pq.top();
        pq.pop();
        if(current < f[i]){
            cout<<"NO"<<endl;
            return;
        }
        current -= f[i];
        if(prev_held > 0){
            pq.push(prev_held);
        }
        prev_held = current;
    }
    cout<<"YES"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}