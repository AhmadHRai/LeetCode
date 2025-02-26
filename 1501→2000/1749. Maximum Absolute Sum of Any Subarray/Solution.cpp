class Solution {
    public:
        // Returns the maximum absolute sum of a subarray
        int maxAbsoluteSum(vector<int>& nums) {
            int minPrefixSum = 0; // Minimum prefix sum encountered so far
            int maxPrefixSum = 0; // Maximum prefix sum encountered so far
    
            int prefixSum = 0; // Current prefix sum
    
            // Iterate through the array
            for (int i = 0; i < nums.size(); i++) {
                // Update the current prefix sum
                prefixSum += nums[i];
    
                // Update the minimum and maximum prefix sums
                minPrefixSum = min(minPrefixSum, prefixSum);
                maxPrefixSum = max(maxPrefixSum, prefixSum);
            }
    
            // Return the difference between the maximum and minimum prefix sums
            return maxPrefixSum - minPrefixSum;
        }
    }
    /*
    Approach Summary:
        This solution uses a prefix sum approach to efficiently find the maximum absolute sum of a subarray. It maintains the minimum and maximum prefix sums encountered 
        during the iteration, and the difference between these two sums gives the maximum absolute sum of any subarray.
    
    Complexity Analysis:
        - Time Complexity: O(N), where N is the number of elements in the array, because each element is processed once.
        - Space Complexity: O(1), excluding the input array, because only a constant amount of space is used.
    */
    