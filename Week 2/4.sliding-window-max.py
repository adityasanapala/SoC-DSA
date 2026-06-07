from collections import deque
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n=len(nums)
        out=[]
        if k>=n:
            out.append(max(nums))
            return out
        else:
            queue=deque()
            for i in range(k):
                queue.append(nums[i])
            out.append(max(queue))    
            for i in range(k,n):
                queue.append(nums[i])
                queue.popleft()
                out.append(max(queue))
            return out    
k=int(input())
nums=list(map(int, input().split()))
solution=Solution()
print(solution.maxSlidingWindow(nums, k))