#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> q;
        for(int i = 0; i < n; i++){
            while(!q.empty() && q.front() <= i-k){
                q.pop_front();
            }
            while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            if(i >= k-1){
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> v;
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        int r;
        cin>>r;
        v.push_back(r);
    }
    Solution s;
    vector<int> result = s.maxSlidingWindow(v,m);
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }

    return 0;
}