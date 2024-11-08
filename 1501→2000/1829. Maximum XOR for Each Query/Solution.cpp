class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        
        // Calculate the XOR of all elements in `nums`
        int xorr = nums[0];
        for (int i = 1; i < n; i++) {
            xorr ^= nums[i];
        }

        // Calculate the maximum XOR value possible with `maximumBit` bits
        int maxxorr = (1 << maximumBit) - 1;  // Equivalent to pow(2, maximumBit) - 1

        // Initialize result vector
        vector<int> ans(n);

        // Compute the result for each prefix in reverse order
        for (int i = 0; i < n; i++) {
            // XOR `xorr` with `maxxorr` to maximize the XOR result for the current prefix
            ans[i] = xorr ^ maxxorr;

            // Remove the last element in the current prefix by XORing it with `xorr`
            xorr ^= nums[n - 1 - i];
        }

        return ans;
    }
};

/*
Approach:
1. Calculate the XOR of all elements in `nums` to initialize `xorr`.
2. Determine `maxxorr`, the maximum possible value with `maximumBit` bits set to 1, as `2^maximumBit - 1`.
3. For each position `i`:
   - Calculate `ans[i]` as `xorr ^ maxxorr`, which maximizes the XOR for the current prefix.
   - Update `xorr` by removing the last element in the current prefix for the next iteration.
4. The result `ans` gives the desired maximum XOR values for each prefix in reverse order.

Complexity Analysis:
- Time Complexity: O(n), where `n` is the length of `nums`, due to two passes through the array.
- Space Complexity: O(n), for the `ans` vector to store results.
*/
