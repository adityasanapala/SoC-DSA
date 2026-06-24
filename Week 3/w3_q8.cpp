#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> a(n);
    for(long long i = 0; i < n; i++){
        cin>>a[i];
    }
    vector<long long> b = a;
    sort(b.begin(), b.end());
    vector<long long> prev(n), curr(n);
    for(int j = 0; j < n; j ++){
        prev[j] = abs(a[0] - b[j]);
    }
    for(int i = 1; i < n; i++){
        long long mn = LLONG_MAX;
        for(int j = 0; j < n; j++){
            mn = min(mn, prev[j]);
            curr[j] = mn + abs(a[i] - b[j]);
        }
        prev = curr;
    }
    cout<< *min_element(prev.begin(), prev.end());
    return 0;
}