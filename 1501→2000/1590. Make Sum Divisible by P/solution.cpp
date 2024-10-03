#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long totalSum = 0;
        // Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        // Find the remainder when total sum is divided by p
        int rem = totalSum % p;
        if (rem == 0) return 0; // If the remainder is 0, no subarray needs to be removed

        // Map to store the last index where a certain prefix sum mod p occurs
        unordered_map<int, int> prefixMod;
        prefixMod[0] = -1;  // Initialize for handling full prefix
        long prefixSum = 0;
        int minLength = nums.size(); // Initialize minLength with size of nums

        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i]; // Calculate the current prefix sum
            int currentMod = prefixSum % p; // Current prefix sum mod p
            int targetMod = (currentMod - rem + p) % p; // Target mod to find

            // Check if targetMod has been seen before
            if (prefixMod.find(targetMod) != prefixMod.end()) {
                // Update minLength if a valid subarray is found
                minLength = min(minLength, i - prefixMod[targetMod]);
            }

            // Update the map with the current mod and index
            prefixMod[currentMod] = i;
        }

        // If no valid subarray found, return -1; otherwise return minLength
        return minLength == nums.size() ? -1 : minLength;
    }
};

/*
  Approach:
  The goal is to find the minimum length of a subarray that can be removed from 
  the original array such that the sum of the remaining elements is divisible by p.
  
  Steps:
  1. Calculate the total sum of the array.
  2. Compute the remainder of the total sum when divided by p.
  3. If the remainder is 0, the entire array is already valid, so return 0.
  4. Use a hash map to track the last occurrence of each prefix sum mod p.
  5. As we iterate through the array:
     - Update the current prefix sum.
     - Compute its mod with p.
     - Determine the target mod that we need to find in order to have the sum of 
       the remaining elements be divisible by p.
     - If the target mod exists in the map, calculate the length of the subarray 
       that can be removed.
     - Update the minimum length if a shorter subarray is found.
  6. Finally, if no valid subarray is found, return -1; otherwise return the 
     minimum length of the subarray to be removed.
  
  Complexity Analysis:
  - Time Complexity: O(N), where N is the number of elements in the array. We 
    traverse the array once while maintaining a hash map for prefix sums.
  - Space Complexity: O(N), for storing the hash map which may contain at most 
    N entries.
 */
