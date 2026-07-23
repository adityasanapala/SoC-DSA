//Sequences
#include <bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> a(n);
    loop(i,0,n){
        cin>>a[i];
    }
    vector<int> s=a;
    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    int m=s.size();
    //dp[i] only depends on dp[i-1] so no need to store i-2,i-3
    vector<long long> prev(m);
    vector<long long> curr(m);
    loop(j,0,m){
        prev[j]=abs(a[0]-s[j]);
    }
    loop(i,1,n){
        long long pref = prev[0];
        loop(j,0,m){
            //for min of prev[0] to prev[j] i.e for last value being s[0] to s[j] no need of running loop for min every time
            pref=min(pref,prev[j]);
            curr[j]=abs(a[i]-s[j]) + pref;
        }
        prev=curr;
    }
    cout << *min_element(curr.begin(),curr.end());
}
