
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
           vector<int> result;
        deque<int> window;   // stores indices

        for (int i = 0; i < nums.size(); i++) {

            // Remove elements that are out of the current window
            if (!window.empty() && window.front() == i - k)
                window.pop_front();

            // Remove all smaller elements from the back
            while (!window.empty() && nums[window.back()] < nums[i])
                window.pop_back();

            window.push_back(i);

            // First complete window formed
            if (i >= k - 1)
                result.push_back(nums[window.front()]);
        }

        return result;
    }




