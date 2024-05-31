/**
 * Finds two unique numbers in the array where every other number appears twice.
 * Uses XOR to find the two numbers based on their differing bit positions.
 *
 * @param nums A vector of integers where each integer appears twice except for two unique numbers.
 * @return A vector containing the two unique numbers.
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int overall_xor = 0;
        
        // Calculate overall XOR of all numbers in nums
        for (int n : nums) {
            overall_xor ^= n;
        }

        // Find the differing bit position between the two unique numbers
        int bit_pos_dif = 0;
        while (((overall_xor >> bit_pos_dif) & 1) != 1) {
            bit_pos_dif++;
        }

        // Initialize variables to store the two unique numbers
        int first_group_xor = 0;
        int second_group_xor = 0;

        // Divide numbers into two groups based on the differing bit position
        for (int num : nums) {
            if (((num >> bit_pos_dif) & 1) == 1) {
                first_group_xor ^= num;
            } else {
                second_group_xor ^= num;
            }
        }

        // Return the two unique numbers found
        return {first_group_xor, second_group_xor};
    }
};

/* 
Algorithm:
    - Compute the overall XOR of all numbers in nums to find the XOR of the two unique numbers.
    - Determine the differing bit position (bit_pos_dif) between the two unique numbers by checking the least significant bits.
    - Divide numbers into two groups based on the differing bit position and compute XOR for each group.
    - The result of first_group_xor and second_group_xor gives the two unique numbers.
    
Complexity Analysis:
    - Time complexity: O(n)
      The function makes two passes through the nums array:
      1. Compute overall XOR of all numbers.
      2. Divide numbers into two groups based on the differing bit position.
      Each pass is O(n), resulting in overall time complexity of O(n).
      
    - Space complexity: O(1)
      The function uses a constant amount of extra space, primarily for variables and return vector {first_group_xor, second_group_xor}.
 */
