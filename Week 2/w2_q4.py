from collections import deque
from typing import List

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        deq = deque()  # stores indices
        output = []

        for i in range(len(nums)):
            # Remove indices outside current window
            while deq and deq[0] <= i - k:
                deq.popleft()

            # Remove smaller elements from the back
            while deq and nums[deq[-1]] <= nums[i]:
                deq.pop()

            deq.append(i)

            # Record answer when first window is complete
            if i >= k - 1:
                output.append(nums[deq[0]])

        return output