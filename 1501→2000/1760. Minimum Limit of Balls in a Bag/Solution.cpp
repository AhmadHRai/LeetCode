class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;         // The minimum possible size of the largest bag
        int high = 1e9;      // The maximum possible size of the largest bag (upper bound)

        // Use binary search to find the smallest maximum bag size that can be achieved with the given number of operations
        while(low < high) {
            int mid = low + (high - low) / 2;  // Find the midpoint, which represents the candidate bag size
            
            int splitOperations = 0;  // Track the total number of operations needed for this candidate size
            for (auto bag : nums) {
                // Calculate how many operations are needed to reduce 'bag' to a size <= mid
                splitOperations += (bag - 1) / mid;
            }

            // If the number of operations exceeds maxOperations, it means the size is too small, so we increase the lower bound
            if (splitOperations > maxOperations) {
                low = mid + 1;
            } else {
                high = mid;  // Otherwise, try smaller sizes
            }
        }
        
        return low;  // The optimal size is the point where low meets high
    }
};

/*
Approach:
1. Use binary search to determine the smallest possible maximum size for a bag that allows splitting within the given operation limit.
2. The range for binary search is from 1 (minimum bag size) to 1e9 (maximum possible size). In each iteration:
   - Calculate `mid`, the candidate size of the largest bag.
   - For each bag, calculate how many splits are needed to make it smaller than or equal to `mid` using the formula `(bag - 1) / mid`.
3. If the total number of splits exceeds `maxOperations`, it means the candidate bag size `mid` is too small, so increase the lower bound (`low = mid + 1`).
4. If the number of splits is within the limit, reduce the upper bound (`high = mid`) and keep searching for a smaller valid bag size.
5. The binary search will converge to the smallest valid maximum bag size that works within the operation limit.

This solution uses binary search to optimize the problem, finding the smallest maximum bag size that satisfies the conditions.

Complexity Analysis:
- Time Complexity: O(n * log(maxValue)), where `n` is the number of bags (`nums.size()`) and `maxValue` is the upper bound of the bag size (1e9). The binary search loop runs `O(log(maxValue))` times, and for each iteration, we iterate over all bags to calculate the number of splits, which takes O(n) time.
- Space Complexity: O(1), as we only use a few variables to track the binary search bounds and the number of split operations.
*/
