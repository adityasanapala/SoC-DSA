#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<unsigned long long> ans;
    unsigned long long t;
    cin>>t;
    for(unsigned long long i = 0; i < t; i++){
        unsigned long long n, k;
        cin>>n>>k;
        vector<unsigned long long> v;
        for(unsigned long long j = 0; j < n; j++){
            unsigned long long x;
            cin>>x;
            v.push_back(x);
        }
        
        vector<int> good(n-1);
        for(int j = 0; j < n - 1; j++){
            good[j] = (v[j] < 2*v[j+1]);
        }
        int curr = 0;
        for(int j = 0; j < k; j++){
            curr += good[j];
        }
        int ans1 = (curr == k);
        for(int j = k; j < n-1; j++){
            curr += good[j];
            curr -= good[j-k];
            if(curr == k) ans1++;
        }
        ans.push_back(ans1);
    }
    unsigned long long m = ans.size();
    for(unsigned long long i = 0; i < m; i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}