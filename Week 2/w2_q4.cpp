//Sliding Window Maximum

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int r=k-1,n=nums.size();
        deque<int> dq;
        vector<int> v;
        // indices in deque
        // 1st element in dq largest
        dq.push_back(0);
        for(int i=1;i<k;i++){
            if(nums[dq.front()]<nums[i]){
                dq.push_front(i);
            }
            else {
                while(!dq.empty()&& nums[dq.back()]<=nums[i]){
                dq.pop_back();
               } dq.push_back(i);
            }
        } 
        v.push_back(nums[dq[0]]);
        r++;
        // front element ou of window remove
        // smaller elements in end wrt new element removed
        //new element added at end
        while(r<n){
            while(!dq.empty()&& dq.front()<r-k+1){
                dq.pop_front();
            }
            while(!dq.empty()&& nums[dq.back()]<=nums[r]){
                dq.pop_back();
               } 
            dq.push_back(r);
            v.push_back(nums[dq.front()]);
            r++;
        }
        return v;
    }
};