class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size();
            int writeIndex = 0;  // Pointer to place non-zero elements
    
            for (int index = 0; index < n; index++) {
                // Step 1: Merge adjacent equal elements if they are non-zero
                if (index < n - 1 && nums[index] == nums[index + 1] &&
                    nums[index] != 0) {
                    nums[index] *= 2;
                    nums[index + 1] = 0;
                }
    
                // Step 2: Shift non-zero elements to the front
                if (nums[index] != 0) {
                    if (index != writeIndex) {
                        swap(nums[index], nums[writeIndex]);
                    }
                    writeIndex++;
                }
            }
    
            return nums;
        }
    };

/* 
Algorithm

    Get the length of nums as n.

    Initialize writeIndex to track the position for non-zero elements.

    Iterate through nums:
        If index is within bounds and nums[index] is equal to nums[index + 1] (both non-zero), merge:
            Double nums[index].
            Set nums[index + 1] to zero.
        If nums[index] is non-zero, move it to writeIndex:
            Swap nums[index] and nums[writeIndex] if needed.
            Increment writeIndex.

    Return the modified nums.

Implementation

    Interview Tip: In-Place Algorithms

    In-place algorithms overwrite the input to save space, but sometimes this can cause problems. Here are a couple of situations where an in-place algorithm might not be suitable:

        The algorithm needs to run in a multi-threaded environment without exclusive access to the array. Other threads might need to read the array as well and may not expect it to be modified.
        Even if there is only a single thread or the algorithm has exclusive access to the array while running, the array might need to be reused later or by another thread once the lock has been released.


Complexity Analysis
    Let n be the size of the nums array.

    Time Complexity: O(n)
        We iterate through the array only once, performing constant-time operations for each element. The merging operation modifies elements in-place, and the shifting 
        of non-zero values is handled dynamically as we iterate, ensuring that no additional passes are required. Since every operation is handled in a single pass, the 
        overall complexity remains linear.

    Space Complexity: O(1)
        The algorithm modifies the input array in place without using extra space. Only a few integer variables are used, which take constant space. Therefore, the 
        overall space complexity is O(1).
*/

