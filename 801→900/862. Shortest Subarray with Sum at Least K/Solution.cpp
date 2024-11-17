class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // Initialize the result variable with a large number.
        // It will store the minimum length of subarray found.
        int res = INT_MAX;
        
        // Initialize the current sum of elements for the sliding window.
        long long curSum = 0;
        
        // Deque to store pairs of (prefix sum, end index) for potential valid subarrays.
        deque<pair<long long, int>> q;  // (prefix_sum, end_idx)
        
        // Iterate through the array elements.
        for (int r = 0; r < nums.size(); r++) {
            // Update the current prefix sum with the current element.
            curSum += nums[r];
            
            // Check if the current prefix sum is already greater than or equal to k.
            // If so, update the result with the minimum subarray length ending at index r.
            if (curSum >= k) {
                res = min(res, r + 1); // Subarray from index 0 to r
            }
            
            // Find the minimum valid window that ends at r.
            while (!q.empty() && curSum - q.front().first >= k) {
                // Pop from the deque as long as the difference between current sum and front prefix sum is >= k.
                auto [prefix, endIdx] = q.front();
                q.pop_front();
                
                // Update the result with the minimum length of the subarray.
                res = min(res, r - endIdx);
            }
            
            // Maintain the monotonicity of the deque.
            // Pop elements from the back of the deque if their prefix sum is greater than the current prefix sum.
            while (!q.empty() && q.back().first > curSum) {
                q.pop_back();
            }
            
            // Push the current prefix sum and its index onto the deque.
            q.push_back({curSum, r});
        }
        
        // If no valid subarray was found, return -1, otherwise return the minimum length.
        return res == INT_MAX ? -1 : res;
    }
};

/*
Approach:
- The problem is solved using the concept of prefix sums and a monotonic deque.
- We compute the prefix sum while iterating over the array, and use a deque to maintain a list of previously encountered prefix sums and their corresponding indices.
- For each element in the array, we check if the current prefix sum (up to that element) is greater than or equal to `k`. If so, we try to update the result.
- We also attempt to find the smallest valid subarray (ending at the current element) by checking if the difference between the current prefix sum and the prefix sum at the front of the deque is greater than or equal to `k`.
- We maintain a monotonic deque where prefix sums are ordered in increasing order, ensuring that we can efficiently find the smallest valid subarray sum.

Time Complexity:
- The algorithm runs in O(n) time, where n is the number of elements in the input array. Each element is pushed to and popped from the deque at most once.

Space Complexity:
- The space complexity is O(n) due to the deque, which stores at most n elements in the worst case.

This solution is efficient and optimal for this problem, leveraging a combination of prefix sums and a monotonic deque to maintain necessary information for solving the problem in linear time.
*/
