class Solution {
public:
    // Method to calculate the minimum number of bit flips required to convert `start` to `goal`
    int minBitFlips(int start, int goal) {
        // Compute the bitwise XOR of `start` and `goal`
        // XOR will highlight the bits that are different between `start` and `goal`
        // Use the built-in function __builtin_popcount to count the number of set bits (1s) in the result of the XOR
        // This count represents the number of bits that differ between `start` and `goal`, i.e., the number of flips needed
        return __builtin_popcount(start^goal);
    }
};

/*
Approach:
1. To determine the number of bit flips required to convert `start` to `goal`, first compute the bitwise XOR of the two numbers. This operation highlights all the bit positions where `start` and `goal` differ.
2. The result of the XOR operation will have a binary representation where each bit set to 1 corresponds to a bit that needs to be flipped.
3. Use the __builtin_popcount function, which efficiently counts the number of 1s in the binary representation of the result from the XOR operation. This count directly gives the number of bit flips needed.
4. The approach leverages the XOR operation and bit counting, which are both efficient operations.

Time Complexity:
- The time complexity is O(1) because the XOR operation and the counting of bits are performed in constant time regardless of the size of the integers.

Space Complexity:
- The space complexity is O(1) because the solution uses only a constant amount of extra space for storing intermediate values.
*/
