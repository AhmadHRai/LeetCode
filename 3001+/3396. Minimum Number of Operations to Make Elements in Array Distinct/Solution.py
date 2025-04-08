# Dec 23 2024
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        operations = 0
        
        while len(nums) > 0:
            if len(nums) == len(set(nums)):
                break
            nums = nums[3:]
            operations += 1

        return operations