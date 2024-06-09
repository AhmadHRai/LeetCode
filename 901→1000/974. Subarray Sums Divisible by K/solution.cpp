/**
 * Solution class for counting subarrays divisible by k.
 */
class Solution {
public:
    /**
     * Counts the number of subarrays in the given array nums
     * whose sum is divisible by k.
     *
     * @param nums A vector of integers representing the input array.
     * @param k An integer representing the divisor.
     * @return The number of subarrays divisible by k.
     */
    int subarraysDivByK(std::vector<int>& nums, int k) {
        int count = 0;  // Initialize count of subarrays divisible by k
        int prefixSum = 0;  // Initialize prefix sum
        std::unordered_map<int, int> prefixMap;  // Map to store count of each remainder
        
        prefixMap[0] = 1;  // Base case: handle subarrays starting from the beginning
        
        for (int num : nums) {
            prefixSum += num;  // Update prefix sum
            
            int mod = prefixSum % k;  // Calculate remainder of prefix sum divided by k
            
            if (mod < 0) {
                mod += k;  // Adjust negative remainders to be positive
            }
            
            if (prefixMap.find(mod) != prefixMap.end()) {
                // If this remainder has been seen before, add its count to the result
                count += prefixMap[mod];
                prefixMap[mod] += 1;  // Increment count of this remainder
            } else {
                prefixMap[mod] = 1;  // Initialize count for this remainder
            }
        }
        
        return count;  // Return total number of subarrays divisible by k
    }
};

/*
Approach:
    1. Prefix Sum Calculation:
        - Use a variable `prefixSum` to maintain the cumulative sum of elements as we iterate through the array `nums`.
    2. Remainder Calculation:
        - Calculate the remainder `mod` of `prefixSum` divided by `k`. Adjust negative remainders to ensure they are positive.
    3. HashMap for Prefix Sums:
        - Use an unordered_map `prefixMap` to store counts of each remainder encountered.
        - Initialize `prefixMap` with {0: 1} to handle subarrays that start from the beginning.
    4. Counting Valid Subarrays:
        - For each element in `nums`, update `prefixSum` and calculate `mod`.
        - If `mod` has been seen before in `prefixMap`, add the count of subarrays ending here (stored in `prefixMap[mod]`) to `count`.
        - Increment the count of `mod` in `prefixMap`.
    5. Return Result:
        - After iterating through `nums`, `count` will contain the total number of subarrays whose sum is divisible by `k`.

Complexity Analysis:
    - Time Complexity: O(n)
      where n is the number of elements in the input array `nums`. We iterate through the array once and perform constant time operations with the hashmap.
    - Space Complexity: O(min(n, k))
      where n is the number of elements in the input array `nums` and k is the value of the integer parameter. The space used by `prefixMap` is bounded by the minimum of n and k.
*/

