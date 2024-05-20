class Solution {
public:
    /**
     * This function calculates the sum of the XOR totals of all subsets of a given vector of integers.
     * The solution uses bit manipulation to generate all possible subsets.
     * 
     * @param nums A vector of integers.
     * @return The sum of the XOR totals of all subsets of nums.
     */
    int subsetXORSum(vector<int>& nums) {
        int res = 0; // Variable to store the final result
        
        // Iterate through all possible subsets (from 1 to 2^n - 1)
        for (auto i = 1; i < (1 << nums.size()); ++i) {
            int total = 0; // Variable to store the XOR total of the current subset
            // Check each bit in i to determine which elements are in the current subset
            for (auto j = 0; j < nums.size(); ++j) {
                if (i & (1 << j)) { // If the j-th bit in i is set, include nums[j] in the subset
                    total ^= nums[j];
                }
            }
            res += total; // Add the XOR total of the current subset to the result
        }
        return res; // Return the final result
    }

    /*
    // This is an alternative implementation that uses a mathematical approach to calculate the sum of XOR totals.
    // It uses the accumulate function to calculate the bitwise OR of all elements and shifts the result by (n - 1).
    int subsetXORSum(vector<int>& n) {
        return accumulate(begin(n), end(n), 0, bit_or<int>()) << (n.size() - 1);
    }
    */
};

/*
Intuition

The problem requires calculating the sum of XOR totals of all subsets of a given vector of integers. We use bit manipulation to generate all possible subsets and calculate their XOR totals.

Algorithm

1. Initialize an integer `res` to store the final result.
2. Iterate through all possible subsets (from 1 to 2^n - 1):
   - For each subset, initialize an integer `total` to store the XOR total of the current subset.
   - Check each bit in the current subset index to determine which elements are included in the subset.
   - If the j-th bit is set, include the j-th element of the vector in the XOR calculation.
   - Add the XOR total of the current subset to the result.
3. Return the final result.

Explanation

In this C++ code:

    The Solution class contains the subsetXORSum method, which calculates the sum of the XOR totals of all subsets of a given vector of integers.
    The subsetXORSum method uses bit manipulation to generate all possible subsets of the input vector.
    It iterates through all possible subsets, calculates the XOR total for each subset, and adds it to the result.

Complexity Analysis

    Let n be the number of elements in the vector.

Time complexity: O(n * 2^n)
- We iterate through all 2^n possible subsets. For each subset, we check n elements to calculate the XOR total. Thus, the overall time complexity is O(n * 2^n).

Space complexity: O(1)
- No additional auxiliary memory proportional to the size of the input is allocated. Thus, the overall space complexity is O(1).
*/
