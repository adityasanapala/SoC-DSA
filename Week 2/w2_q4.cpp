class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> window;
        vector<int> maximums;

        for(int i = 0; i < k; i++){
            while(window.size() > 0 && nums[window.back()] < nums[i]){
                window.pop_back();
            }
            window.push_back(i);
        }

        for(int i = k; i < nums.size(); i++){
            maximums.push_back(nums[window.front()]);

            while(window.size() > 0 && window.front() <= i - k){
                window.pop_front();
            }
            while(window.size() > 0 && nums[window.back()] < nums[i]){
                window.pop_back();
            }
            window.push_back(i);
            
        }
        maximums.push_back(nums[window.front()]);

        return maximums;
    }
};