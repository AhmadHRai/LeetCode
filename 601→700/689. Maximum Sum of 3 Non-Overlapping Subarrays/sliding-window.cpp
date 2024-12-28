class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Arrays to store the best start indices
        int bestSingleStart = 0;
        vector<int> bestDoubleStart = {0, k};
        vector<int> bestTripleStart = {0, k, 2 * k};

        // Compute initial window sums
        int currentWindowSumSingle = accumulate(nums.begin(), nums.begin() + k, 0);
        int currentWindowSumDouble = accumulate(nums.begin() + k, nums.begin() + 2 * k, 0);
        int currentWindowSumTriple = accumulate(nums.begin() + 2 * k, nums.begin() + 3 * k, 0);

        // Track the best sums found so far
        int bestSingleSum = currentWindowSumSingle;
        int bestDoubleSum = currentWindowSumSingle + currentWindowSumDouble;
        int bestTripleSum = bestDoubleSum + currentWindowSumTriple;

        // Sliding window pointers
        int singleStartIndex = 1;
        int doubleStartIndex = k + 1;
        int tripleStartIndex = 2 * k + 1;

        // Slide the windows across the array
        while (tripleStartIndex <= n - k) {
            // Update sums using sliding window
            currentWindowSumSingle += nums[singleStartIndex + k - 1] - nums[singleStartIndex - 1];
            currentWindowSumDouble += nums[doubleStartIndex + k - 1] - nums[doubleStartIndex - 1];
            currentWindowSumTriple += nums[tripleStartIndex + k - 1] - nums[tripleStartIndex - 1];

            // Update best single subarray
            if (currentWindowSumSingle > bestSingleSum) {
                bestSingleStart = singleStartIndex;
                bestSingleSum = currentWindowSumSingle;
            }

            // Update best double subarray
            if (currentWindowSumDouble + bestSingleSum > bestDoubleSum) {
                bestDoubleStart[0] = bestSingleStart;
                bestDoubleStart[1] = doubleStartIndex;
                bestDoubleSum = currentWindowSumDouble + bestSingleSum;
            }

            // Update best triple subarray
            if (currentWindowSumTriple + bestDoubleSum > bestTripleSum) {
                bestTripleStart[0] = bestDoubleStart[0];
                bestTripleStart[1] = bestDoubleStart[1];
                bestTripleStart[2] = tripleStartIndex;
                bestTripleSum = currentWindowSumTriple + bestDoubleSum;
            }

            // Increment pointers
            singleStartIndex++;
            doubleStartIndex++;
            tripleStartIndex++;
        }

        return bestTripleStart;
    }
};

/*
- **Intuition**:
    Use sliding windows to compute the maximum sum of three non-overlapping subarrays.
    Keep track of the best sums and their indices for one, two, and three subarrays incrementally.

- **Algorithm**:
    1. Compute the initial sums for the first three windows.
    2. Slide the windows and update the sums using the sliding window technique.
    3. Update the best indices and sums for single, double, and triple subarrays as you process the array.
    4. Return the indices of the starting points for the three subarrays with the maximum sum.

- **Complexity**:
    - Time Complexity: **O(n + k)**  
        - Initial sum computations: **O(k)**.
        - Sliding window traversal: **O(n)**.
    - Space Complexity: **O(1)**  
        - Constant extra space used for tracking indices and sums.
*/
