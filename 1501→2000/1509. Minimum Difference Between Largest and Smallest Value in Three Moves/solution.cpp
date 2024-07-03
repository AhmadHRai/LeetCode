class Solution {
public:
    // Function to calculate the minimum difference between the largest and smallest elements after removing three elements
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort the input array in non-decreasing order
        int minVal = INT_MAX;  // Initialize minVal to a large value
        int n = nums.size();  // Get the size of the input array
        
        if (n <= 4) return 0;  // If there are 4 or fewer elements, return 0 as no elements can be removed

        // Calculate the minimum difference by considering all possible combinations of removing three elements
        minVal = min(minVal, nums[n - 4] - nums[0]);  // Remove the first three elements
        minVal = min(minVal, nums[n - 1] - nums[3]);  // Remove the last three elements
        minVal = min(minVal, nums[n - 2] - nums[2]);  // Remove the second and third elements
        minVal = min(minVal, nums[n - 3] - nums[1]);  // Remove the first and last two elements

        return minVal;  // Return the minimum difference found
    }
};

/* 
Approach:
    Sorting:
    - The `minDifference` function begins by sorting the input vector `nums` in non-decreasing order to simplify the process of finding the minimum difference.
    
    Calculation of Minimum Difference:
    - After sorting, it calculates the minimum difference between the largest and smallest elements of the array after removing exactly three elements.
    - It considers four possible scenarios by removing:
      1. The first three elements (`nums[0]`, `nums[1]`, `nums[2]`).
      2. The last three elements (`nums[n-1]`, `nums[n-2]`, `nums[n-3]`).
      3. The second and third elements (`nums[1]`, `nums[2]`).
      4. The first and last two elements (`nums[0]`, `nums[n-1]`).
    
    Complexity:
    - Time Complexity: O(n log n) due to sorting, where n is the size of the input vector `nums`. Sorting dominates the time complexity.
    - Space Complexity: O(1) auxiliary space, excluding the input vector `nums`. The function uses a constant amount of extra space for variables regardless of the input size.
*/
