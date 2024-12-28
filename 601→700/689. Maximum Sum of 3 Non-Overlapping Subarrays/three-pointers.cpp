class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxSum = 0;

        // Prefix sum array to calculate sum of any subarray
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // Arrays to store the best starting index for the left and right
        // subarrays
        vector<int> leftMaxIndex(n);
        vector<int> rightMaxIndex(n);

        // Result array to store the starting indices of the three subarrays
        vector<int> result(3);

        // Calculate the best starting index for the left subarray for each
        // position
        for (int i = k, currentMaxSum = prefixSum[k] - prefixSum[0]; i < n;
             i++) {
            if (prefixSum[i + 1] - prefixSum[i + 1 - k] > currentMaxSum) {
                leftMaxIndex[i] = i + 1 - k;
                currentMaxSum = prefixSum[i + 1] - prefixSum[i + 1 - k];
            } else {
                leftMaxIndex[i] = leftMaxIndex[i - 1];
            }
        }

        // Calculate the best starting index for the right subarray for each
        // position
        rightMaxIndex[n - k] = n - k;
        for (int i = n - k - 1, currentMaxSum = prefixSum[n] - prefixSum[n - k];
             i >= 0; i--) {
            if (prefixSum[i + k] - prefixSum[i] >= currentMaxSum) {
                rightMaxIndex[i] = i;
                currentMaxSum = prefixSum[i + k] - prefixSum[i];
            } else {
                rightMaxIndex[i] = rightMaxIndex[i + 1];
            }
        }

        // Iterate over the middle subarray and calculate the total sum for all
        // valid combinations
        for (int i = k; i <= n - 2 * k; i++) {
            int leftIndex = leftMaxIndex[i - 1];
            int rightIndex = rightMaxIndex[i + k];
            int totalSum = (prefixSum[i + k] - prefixSum[i]) +
                           (prefixSum[leftIndex + k] - prefixSum[leftIndex]) +
                           (prefixSum[rightIndex + k] - prefixSum[rightIndex]);

            if (totalSum > maxSum) {
                maxSum = totalSum;
                result[0] = leftIndex;
                result[1] = i;
                result[2] = rightIndex;
            }
        }

        return result;
    }
};

/* 
Intuition:
    - We divide the problem into three regions by fixing the position of the middle subarray.
    - The left region (before the middle subarray) requires us to find the best left subarray.
    - The middle subarray is fixed.
    - The right region (after the middle subarray) requires us to find the best right subarray.
    - By precomputing two arrays, `leftMaxIndex` and `rightMaxIndex`, we can efficiently track the best subarrays for the left and right regions.
    - For each possible middle subarray, we calculate the total sum of the best left, middle, and right subarrays.

Algorithm:
    - Compute a prefix sum array to calculate the sum of any subarray.
    - Build `leftMaxIndex` to store the best left subarray starting index for each position.
    - Build `rightMaxIndex` to store the best right subarray starting index for each position.
    - Iterate over all valid middle subarray positions, calculate the total sum for each combination, and track the maximum sum.

Complexity Analysis:
    - Time Complexity: O(n)
        - We perform four linear scans: one for the prefix sum, one for `leftMaxIndex`, one for `rightMaxIndex`, and one for the middle subarray.
        - Therefore, the time complexity is O(n).
    - Space Complexity: O(n)
        - We use three arrays (`prefixSum`, `leftMaxIndex`, and `rightMaxIndex`) of size O(n), so the space complexity is O(n).
 */