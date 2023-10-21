class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        dp = nums[:1]
        decrease = collections.deque(dp)
        for i, x in enumerate(nums[1:], 1):
            if i > k and decrease[0] == dp[i - k - 1]:
                decrease.popleft()
            tmp = max(x, decrease[0] + x)
            dp += tmp,
            while decrease and decrease[-1] < tmp:
                decrease.pop()
            decrease += tmp,
        return max(dp)


""" 
The Idea is straight-forward, we can maintain an non-increasing deque decrease that records the maximum value among dp[i - k], dp[i-k+1], ..., dp[i - 1]. When encountering a 
new value x, we only record it in decrease if x > decrease[decrease.size - 1]. Thus the first element in decrease will always be the largest value we want.

Complexity
Time: O(n)
Space: O(n)
"""
