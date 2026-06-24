#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> v(n);
    for(long long i = 0; i < n; i++){
        cin>>v[i];
    }
    long long m = v.size();
    vector<long long> even;
    vector<long long> odd;
    long long ce = 0;
    long long co = 0;
    for(long long i = 0; i < m; i++){
        if(v[i]%2 == 0){
            ce++;
            even.push_back(i);
        }
        else{
            co++;
            odd.push_back(i);
        }
    }
    long long ans = 0;
    if(even.size() == 1) ans = even[0];
    else ans = odd[0];
    cout<<ans+1<<endl;
    return 0;
}