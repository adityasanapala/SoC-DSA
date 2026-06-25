#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<int, int> lastPos;
    
    int left=0;
    int ans=0;

    for(int right=0; right<n; right++){

        if(lastPos.count(arr[right]) && lastPos[arr[right]]>=left){
            left=lastPos[arr[right]]+1;
        }
        lastPos[arr[right]]=right;
        
        ans=max(ans, right-left+1);
    }
    cout<<ans<<endl;
    return 0;    
}