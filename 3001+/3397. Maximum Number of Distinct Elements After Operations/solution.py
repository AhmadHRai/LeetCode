class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        nums.sort() 
        distinct = set()
        next_available = float('-inf')
        
        for num in nums:
            start = max(num - k, next_available)
            if start <= num + k:
                distinct.add(start)
                next_available = start + 1 
        
        return len(distinct)