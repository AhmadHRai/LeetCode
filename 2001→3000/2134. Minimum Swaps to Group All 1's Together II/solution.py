class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        ones = nums.count(1)  # Count the total number of 1's in the array
        nums = nums + nums  # Concatenate the array with itself to handle circular window cases
        x, onesInWindow = 0, 0  # Initialize variables: x for the number of 1's in the current window, onesInWindow for the max found
        
        # Iterate over each element in the doubled array
        for i in range(len(nums)):
            # If the window is of size greater than the number of 1's, adjust the count by removing the leftmost element
            if i >= ones and nums[i - ones]:
                x -= 1
            # If the current element is 1, increment the count
            if nums[i] == 1:
                x += 1
            # Update the maximum number of 1's found in any window of size 'ones'
            onesInWindow = max(x, onesInWindow)
        
        # Return the minimum number of swaps needed, which is the number of 1's minus the maximum number of 1's in any window of size 'ones'
        return ones - onesInWindow

"""
Approach:
- Count the total number of 1's in the input array `nums`.
- Double the array by concatenating it with itself to handle the circular nature of the problem.
- Use a sliding window technique to find the window of length equal to the number of 1's (`ones`) that contains the maximum number of 1's.
- Track the number of 1's in the current window and update the maximum number of 1's found.
- The minimum number of swaps required is the difference between the total number of 1's and the maximum number of 1's in the best window.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the original array. We make a single pass through the doubled array.
- Space Complexity: O(n), due to the storage of the doubled array.
"""
