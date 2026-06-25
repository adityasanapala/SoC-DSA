#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,sum;
cin >> n >> sum;
map<int, int> nums;
for(int i=1;i<=n;i++){
    int current;
    cin >> current;
    int reqd = sum - current;
    if(nums.count(reqd)>0){
        cout<<nums[reqd]<<' '<<i;
        return 0;
    }
    nums[current]=i;
}
cout << "IMPOSSIBLE";
}