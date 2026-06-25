#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;        
        for (int i = 0; i <= n - k; i++) {
            int mx = nums[i];          
            for (int j = 0; j < k; j++) {
                mx = max(mx, nums[i + j]);
            }            
            res.push_back(mx);
        }       
        return res; 
    }
};