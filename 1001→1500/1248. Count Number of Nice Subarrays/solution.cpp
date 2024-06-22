class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> cntOdds(n + 1, 0); // 1-Indexed prefix sum count of odds

        // Create the prefix sum array for counting odds
        for (int i = 0; i < n; i++) {
            cntOdds[i + 1] = cntOdds[i] + (nums[i] & 1); // Increment if nums[i] is odd
        }

        int l = 0, cnt = 0; // Initialize left pointer and count of subarrays

        for (int r = 0; r < n; r++) {
            // Ensure the current window [l, r] has at least K odd numbers
            while (l <= r && cntOdds[r + 1] - cntOdds[l] > k) {
                l++; // Move left pointer to the right until we have at most K odds
            }

            // If the current window [l, r] has exactly k odd numbers
            if (cntOdds[r + 1] - cntOdds[l] == k) {
                int l0 = l;
                // Count nice subarrays ending at r
                while (l0 <= r && cntOdds[r + 1] - cntOdds[l0] == k) {
                    cnt++; // Increment count for each valid subarray
                    l0++; // Move left pointer to count all possible subarrays
                }
            }
        }
        return cnt; // Return the total count of valid subarrays
    }
};

/*
Approach:
- Use a prefix sum technique to count the number of odd numbers in any subarray.
- Maintain a prefix array `cntOdds` where `cntOdds[i]` gives the count of odd numbers from nums[0] to nums[i-1].
- Iterate through the array with two pointers, `l` (left) and `r` (right), to define the current window [l, r].
- Adjust `l` such that the window [l, r] contains exactly `k` odd numbers or fewer.
- Count subarrays ending at `r` that satisfy the condition of exactly `k` odd numbers.
- Use a nested loop to count all valid subarrays ending at `r` by iterating `l0` from `l` to `r`.
- Return the total count of valid subarrays.

Complexity Analysis:
- Time Complexity: O(n^2), where n is the size of the input array `nums`.
  - Two nested loops: the outer loop runs `r` from 0 to n-1 and the inner loop runs `l0` from `l` to `r`.
  - Each iteration of the inner loop takes O(1) time on average due to constant time operations with prefix sums.
  - In the worst case, when all elements are odd, the inner loop could run up to n times for each value of `r`.
- Space Complexity: O(n), due to the additional space used by the prefix sum array `cntOdds`.
  - The space complexity is dominated by the prefix sum array which has a size of n+1 to store cumulative counts of odd numbers.
*/
