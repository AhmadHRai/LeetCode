class Solution {
    public:
        int maxAscendingSum(vector<int>& nums) {
            int maxSum = 0;
    
            // Outer loop to start from each element in the array
            for (int startIdx = 0; startIdx < nums.size(); startIdx++) {
                int currentSubarraySum = nums[startIdx];
    
                // Inner loop to check the next elements forming an ascending
                // subarray
                for (int endIdx = startIdx + 1;
                     endIdx < nums.size() && nums[endIdx] > nums[endIdx - 1];
                     endIdx++) {
                    currentSubarraySum += nums[endIdx];
                }
    
                // Update maxSum if we find a larger ascending subarray sum
                maxSum = max(maxSum, currentSubarraySum);
            }
    
            return maxSum;
        }
    };

/* 
Algorithm

    Initialize maxSum to 0, which will store the maximum sum of an ascending subarray.

    Use an outer loop to iterate over each element in the array (nums[startIdx]):
        Set currentSubarraySum to nums[startIdx] to start a new ascending subarray from this element.

    Use an inner loop to check the next elements forming an ascending subarray:
        Continue adding to currentSubarraySum while the next element (nums[endIdx]) is greater than the previous element (nums[endIdx - 1]).
        Stop the inner loop when the subarray is no longer ascending or when the end of the array is reached.

    After checking the subarray, update maxSum if currentSubarraySum is greater than the current maxSum.

    After processing all possible subarrays, return maxSum, which contains the largest sum of an ascending subarray.

Complexity Analysis

    Let n be the size of the input array nums.

    Time complexity: O(n^2)

        The algorithm uses a nested loop structure. The outer loop runs n times, iterating over each element in the array. For each iteration of the outer loop, the inner 
        loop starts from the current element and continues as long as the next element is greater than the previous one (forming an ascending subarray). In the worst 
        case, the inner loop could run up to n times (e.g., when the entire array is strictly increasing).

        Therefore, the time complexity is O(n^2).

    Space complexity: O(1)

        The algorithm uses a constant amount of extra space. The variables maxSum, currentSubarraySum, startIdx, and endIdx are the only additional space used, and they 
        do not depend on the size of the input array. No additional data structures or recursive calls are used that would increase the space complexity.

    Therefore, the space complexity is O(1).

*/