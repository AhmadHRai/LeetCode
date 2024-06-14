class Solution {
public:
    /**
     * Calculates the minimum number of increments required to make all elements unique in the array.
     * 
     * @param {vector<int>&} nums - The array of integers to modify.
     * @return {int} - The minimum number of increments needed.
     */
    int minIncrementForUnique(vector<int>& nums) {
        // Sort the array to handle duplicates efficiently
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        // Traverse the sorted array and fix any duplicates
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                // Calculate the increment needed to make nums[i] unique
                ans += nums[i - 1] - nums[i] + 1;
                // Update nums[i] to be one more than nums[i - 1]
                nums[i] = nums[i - 1] + 1;
            }
        }
        
        return ans;
    }
};

/*
Approach:
    1. Sorting:
        - Sort the input array `nums` to handle duplicates efficiently.
    2. Increment Calculation:
        - Traverse the sorted array.
        - If a duplicate is found (nums[i] <= nums[i - 1]), calculate the increment needed to make nums[i] unique.
        - Update nums[i] to ensure it is greater than nums[i - 1].
    3. Accumulate Increment:
        - Accumulate the total number of increments required in `ans`.
    4. Return:
        - Return the accumulated `ans`, which represents the minimum number of increments needed to make all elements unique.

Complexity:
    - Time Complexity: O(n log n)
      Sorting the array dominates the complexity. The subsequent linear pass through the array is O(n), which doesn't dominate due to sorting.
    - Space Complexity: O(1) or O(n)
      The space used is primarily for the input array `nums`. Sorting in-place typically requires O(1) extra space, but sorting itself may use O(n) space depending on the implementation.

Notes:
    - This approach ensures that each element in the array `nums` is unique by incrementing duplicates as necessary.
    - Edge cases, such as empty arrays or arrays with all unique elements, are handled gracefully by the sorting and increment logic.
*/

