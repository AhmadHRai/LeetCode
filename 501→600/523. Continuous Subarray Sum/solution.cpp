/**
 * Solution class for checking if there exists a subarray with a sum that is a multiple of k.
 */
class Solution {
public:
    /**
     * Checks if there exists a contiguous subarray in the given array nums
     * such that the sum of elements in the subarray is a multiple of k.
     *
     * @param nums A vector of integers representing the input array.
     * @param k An integer representing the target multiple.
     * @return True if such a subarray exists, false otherwise.
     */
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixMod = 0;  // Initialize prefix sum modulo k
        unordered_map<int, int> modSeen;  // Map to store seen prefix mod values
        modSeen[0] = -1;  // Initialize with prefix mod 0 at index -1 (base case)

        for (int i = 0; i < nums.size(); i++) {
            prefixMod = (prefixMod + nums[i]) % k;  // Update prefix sum modulo k

            if (modSeen.find(prefixMod) != modSeen.end()) {
                // Check if current index minus index of previous same prefix mod is more than 1
                if (i - modSeen[prefixMod] > 1) {
                    return true;  // Found a valid subarray, return true
                }
            } else {
                modSeen[prefixMod] = i;  // Record the first occurrence of this prefix mod
            }
        }

        return false;  // No valid subarray found, return false
    }
};

/*
Approach:
    1. Prefix Modulo Calculation:
        - Use a variable `prefixMod` to keep track of the cumulative sum of elements modulo k as we iterate through the array.
    2. Map to Store Seen Prefix Mod Values:
        - Use an unordered_map `modSeen` to store each `prefixMod` value encountered along with its index.
        - Initialize `modSeen` with {0: -1} to handle cases where the sum from the start to the current index is a multiple of k.
    3. Iteration and Checking:
        - Iterate through the array `nums`.
        - Update `prefixMod` for each element in `nums`.
        - Check if `prefixMod` has been seen before in `modSeen`.
        - If yes, calculate the length of the subarray and check if it's greater than 1.
        - If no, record the current index of `prefixMod` in `modSeen`.
    4. Return Result:
        - If a valid subarray with sum divisible by k is found, return true.
        - If no such subarray is found after iterating through the entire array, return false.

Complexity Analysis:
    - Time Complexity: O(n)
      where n is the number of elements in the input array nums. We iterate through the array once and perform constant time operations with the hashmap.
    - Space Complexity: O(min(n, k))
      where n is the number of elements in the input array nums and k is the value of the integer parameter. The space used by `modSeen` is bounded by the minimum of n and k.
*/

