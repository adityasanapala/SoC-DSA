#include<bits/stdc++.h>
using namespace std;

int main(){
    int ans = INT_MIN;
    vector<int> v;
    int n, k;
    cin>>n>>k;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
   unordered_map<int,int> m;
   int l = 0;
   int bl = 0;
   int br = 0;
   for(int r = 0; r < n; r++){
    m[a[r]]++;
    while(int(m.size()) > k){
        m[a[l]]--;
        if(m[a[l]] == 0) m.erase(a[l]);
        l++;
    }
    if(r - l > br - bl){
        br = r;
        bl = l;
    }
   }
   cout<<bl+1<<" "<<br+1<<endl;
    return 0;
}