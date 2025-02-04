class Solution {
    public:
        int maxAscendingSum(vector<int>& nums) {
            int maxSum = 0;
            int currentSubarraySum = nums[0];
    
            // Loop through the array starting from the second element
            for (int currentIdx = 1; currentIdx < nums.size(); ++currentIdx) {
                if (nums[currentIdx] <= nums[currentIdx - 1]) {
                    // If the current element is not greater than the previous one,
                    // update maxSum
                    maxSum = max(maxSum, currentSubarraySum);
                    // Reset the sum for the next ascending subarray
                    currentSubarraySum = 0;
                }
                currentSubarraySum += nums[currentIdx];
            }
    
            // Final check after the loop ends to account for the last ascending
            // subarray
            return max(maxSum, currentSubarraySum);
        }
    };

/* 
Algorithm

    Initialize maxSum to 0, which will store the maximum sum of an ascending subarray.

    Initialize currentSubarraySum to the first element of the nums array, which tracks the sum of the current ascending subarray.

    Loop through the array starting from the second element:
        Compare each element with the previous one:
            If the current element is less than or equal to the previous one:
                Update maxSum with the maximum value between the current maxSum and currentSubarraySum.
                Reset currentSubarraySum to 0, as a new ascending subarray will start.
        Add the current element's value to currentSubarraySum to continue summing the ascending subarray.

    After the loop ends, perform a final check to account for the last ascending subarray:
        Return the maximum value between maxSum and currentSubarraySum, which is the sum of the largest ascending subarray.


Complexity Analysis
    Let n be the size of the input array nums.

    Time complexity: O(n)

        The algorithm iterates through the array nums exactly once. During each iteration, it performs a constant amount of work: comparing the current element with the 
        previous one, updating maxSum, and resetting currentSubarraySum if necessary. The max function, which is a built-in function, also operates in constant time O(1).

        Therefore, the overall time complexity is linear with respect to the size of the input array.

    Space complexity: O(1)

        The algorithm uses a constant amount of extra space regardless of the input size. The variables maxSum and currentSubarraySum are the only additional space used, 
        and they do not depend on the size of the input array.

        Therefore, the space complexity is constant, O(1).

*/