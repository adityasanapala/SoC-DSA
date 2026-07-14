#include<bits/stdc++.h>
using namespace std;

bool isvalid(const vector<int>& a, int k, int x, int parity){
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        if(count%2 == parity){
            if(a[i] <= x){
                count++;
            }
        }
        else{
            count++;
        }
    }
    return count >= k;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int low = 1;
    int high = 1e9;
    int ans = high;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(isvalid(a,k,mid,0) || isvalid(a,k,mid,1)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}